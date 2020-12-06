#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "file_reader.h"
#define UNALLOCATED 0x00
#define DELETED 0xe5
#define FILE_NAME 8
#define FILE_EXT 3
#define SECTOR_SIZE 512
#define VOLUMIN_SIGNATURE 0xAA55 // Value from resources, author of the task suggests 0x55AA BIG vs. LITTLE endian?
#define LAST_CLUSTER 0xffff
#define POWER_OF_TWO(x) ((x & (x - 1)) && x)    // check if value is a power of two
#define MAX_CLUSTER_SIZE 64
#define FIRST_CLUSTER(x, y)  ((x << 16) | y)    // calculate the file first cluster


struct disk_t* disk_open_from_file(const char* volume_file_name){

    if (volume_file_name == NULL){

        errno = EFAULT;
        return NULL;
    }

    struct disk_t * disk = calloc(1, sizeof(struct disk_t));

    if (disk == NULL){

        errno = ENOMEM;
        return NULL;
    }

    if((disk->file = fopen(volume_file_name, "rb")) == NULL){

        free(disk);
        errno = ENOENT;
        return NULL;
    }

    fseek(disk->file, 0, SEEK_END);

    disk->many_sectors = ftell(disk->file) / SECTOR_SIZE;

    return disk;
}

int disk_read(struct disk_t* pdisk, int32_t first_sector, void* buffer, int32_t sectors_to_read){

    if (buffer == NULL || pdisk == NULL || pdisk->file == NULL){

        errno = EFAULT;
        return -1;
    }
    else if(first_sector < 0 || sectors_to_read < 0 || sectors_to_read > (int32_t)pdisk->many_sectors - first_sector){

        errno = ERANGE;
        return -1;
    }

    fseek(pdisk->file, first_sector * SECTOR_SIZE, SEEK_SET);
    fread(buffer, SECTOR_SIZE, sectors_to_read, pdisk->file);

    return sectors_to_read;
}

int disk_close(struct disk_t* pdisk){

    if (pdisk == NULL || pdisk->file == NULL){

        errno = EFAULT;
        return -1;
    }

    fclose(pdisk->file);
    free(pdisk);
    pdisk = NULL;

    return 0;
}

struct volume_t* fat_open(struct disk_t* pdisk, uint32_t first_sector){

    if (pdisk == NULL){

        errno = EFAULT;
        return NULL;
    }

    struct volume_t * volumin = calloc(1, sizeof(struct volume_t));
    struct extended_BPB * boot_sec = calloc(1, sizeof(struct extended_BPB));

    if (volumin == NULL || boot_sec == NULL){

        free(boot_sec);
        free(volumin);
        errno = ENOMEM;
        return NULL;
    }

    if (-1 == disk_read(pdisk, first_sector, boot_sec, 1)){

        free(volumin);
        free(boot_sec);
        return NULL;
    }

    if (boot_sec->BPB_info.num_of_sects_in_fsys > 0 && boot_sec->BPB_info.num_of_sects_in_fsys == pdisk->many_sectors){

        volumin->num_of_sectors = boot_sec->BPB_info.num_of_sects_in_fsys;
    }
    else if (boot_sec->BPB_info.sec_num_of_sects_in_fsys > 0 && boot_sec->BPB_info.sec_num_of_sects_in_fsys == pdisk->many_sectors){

        volumin->num_of_sectors = boot_sec->BPB_info.sec_num_of_sects_in_fsys;
    }
    else{

        errno = EINVAL;
        free(volumin);
        free(boot_sec);
        return NULL;
    }

    if (boot_sec->BPB_info.b_per_sect != SECTOR_SIZE){

        errno = EINVAL;
        free(volumin);
        free(boot_sec);
        return NULL;
    }
    else{

        volumin->bytes_per_sector = boot_sec->BPB_info.b_per_sect;
    }

    if (boot_sec->sign_value != VOLUMIN_SIGNATURE){

        errno = EINVAL;
        free(volumin);
        free(boot_sec);
        return NULL;
    }

    if (0 == strncmp((const char*)boot_sec->file_sys_type, "FAT12", 5)){

        volumin->type = 12;
    }
    else if (0 == strncmp((const char*)boot_sec->file_sys_type, "FAT16", 5)){

        volumin->type = 16;
    }
    else{

        errno = EINVAL;
        free(volumin);
        free(boot_sec);
        return NULL;
    }

    if (boot_sec->BPB_info.reserved_sects == 0){

        errno = EINVAL;
        free(volumin);
        free(boot_sec);
        return NULL;
    }
    else{

        volumin->boot_size = boot_sec->BPB_info.reserved_sects;
    }

    if (boot_sec->BPB_info.sects_per_fat == 0){

        errno = EINVAL;
        free(volumin);
        free(boot_sec);
        return NULL;
    }
    else{

        volumin->fat_size = boot_sec->BPB_info.sects_per_fat * volumin->bytes_per_sector;
        volumin->sects_per_fat = boot_sec->BPB_info.sects_per_fat;
    }

    if (boot_sec->BPB_info.num_of_fats == 0){

        errno = EINVAL;
        free(volumin);
        free(boot_sec);
        return NULL;
    }
    else{

        volumin->num_of_fats = boot_sec->BPB_info.num_of_fats;
    }

    if (POWER_OF_TWO(boot_sec->BPB_info.sects_per_clust) || boot_sec->BPB_info.sects_per_clust > MAX_CLUSTER_SIZE){

        errno = EINVAL;
        free(volumin);
        free(boot_sec);
        return NULL;
    }
    else{

        volumin->cluster_size = boot_sec->BPB_info.sects_per_clust;
    }

    if (boot_sec->BPB_info.max_num_of_root_dir == 0){

        errno = EINVAL;
        free(volumin);
        free(boot_sec);
        return NULL;
    }
    else{

        volumin->num_of_files_root_dir = boot_sec->BPB_info.max_num_of_root_dir;
        volumin->root_dir_size = volumin->num_of_files_root_dir * sizeof(struct SFN) / volumin->bytes_per_sector;
    }

    uint8_t * fats_data = calloc(volumin->num_of_fats, volumin->fat_size);

    if (-1 == disk_read(pdisk, volumin->boot_size, fats_data, volumin->sects_per_fat * volumin->num_of_fats)){

        free(fats_data);
        free(volumin);
        free(boot_sec);
        return NULL;
    }

    for (uint32_t i = 0; i < volumin->num_of_fats - 1u; ++i){

        if (0 != memcmp(fats_data + i * volumin->fat_size, fats_data + (i + 1) * volumin->fat_size, volumin->fat_size)){

            errno = EINVAL;
            free(fats_data);
            free(volumin);
            free(boot_sec);
            return NULL;
        }
    }

    volumin->clusters_indexes = calloc(volumin->fat_size / 3 * 2 + 1, sizeof(uint16_t));

    if (volumin->clusters_indexes == NULL){

        errno = EINVAL;
        free(fats_data);
        free(volumin);
        free(boot_sec);
        return NULL;
    }

    if (volumin->type == 12){

        uint32_t index = 0;
        uint16_t value;
        for (uint32_t i = 0; i < volumin->fat_size; ++i){

            if (i % 3 == 0){

                value = *(fats_data + i + 1) & 0x0f;
                value <<= 8;
                value |= *(fats_data + i);

                if (value == 0x0fff){
                    *(volumin->clusters_indexes + index) = LAST_CLUSTER;
                }
                else{
                    *(volumin->clusters_indexes + index) = value;
                }
                index++;
            }
            else if (i % 3 == 2){

                value = *(fats_data + i) << 4;
                value |= (*(fats_data + i - 1) >> 4);

                if (value == 0x0fff){
                    *(volumin->clusters_indexes + index) = LAST_CLUSTER;
                }
                else{
                    *(volumin->clusters_indexes + index) = value;
                }
                index++;
            }
        }
    }
    else{

        for (uint32_t i = 0; i < volumin->fat_size; i += 2){

            *(volumin->clusters_indexes + i/2) = *((uint16_t*)(fats_data + i));
        }
    }

    volumin->disk = pdisk;
    volumin->bef_data_size = volumin->boot_size + volumin->num_of_fats * volumin->sects_per_fat + volumin->root_dir_size;

    free(fats_data);
    free(boot_sec);
    return volumin;
}

int fat_close(struct volume_t* pvolume){

    if (pvolume == NULL){

        errno = EFAULT;
        return -1;
    }

    free(pvolume->clusters_indexes);
    free(pvolume);
    pvolume = NULL;

    return 0;
}

struct file_t* file_open(struct volume_t* pvolume, const char* file_name){

    if (pvolume == NULL || file_name == NULL){

        errno = EFAULT;
        return NULL;
    }

    if (file_name[strlen(file_name)-1] == '\\'){

        errno = EISDIR;
        return NULL;
    }

    uint32_t last_bslash = 0;

    for (uint32_t i = 0; i < strlen(file_name); ++i){

        if (file_name[i] == '\\'){
            last_bslash = i;
        }
    }

    char * temp_path = calloc(1, last_bslash + 2);

    if (temp_path == NULL){

        errno = ENOMEM;
        return NULL;
    }

    if (last_bslash == 0 && file_name[0] != '\\'){

        strcpy(temp_path, "\\");    //check if NULL at the end 
        temp_path[last_bslash + 1] = '\0';
    }
    else{
        strncpy(temp_path, file_name, last_bslash + 1);
        temp_path[last_bslash + 1] = '\0';
    }

    struct dir_t * final_dir = dir_open(pvolume, temp_path);    // here problem

    free(temp_path);

    if (final_dir == NULL){

        return NULL;
    }

    struct file_t * final_file = calloc(1, sizeof(struct file_t));

    if  (final_file == NULL){

        free(final_dir);
        errno = ENOMEM;
        return NULL;
    }

    struct dir_entry_t dir_file;
    int32_t flag = dir_read(final_dir, &dir_file);
    while (flag == 0){

        if (own_strcmp(file_name + last_bslash, dir_file.name) == 0){

            if (dir_file.is_directory == 1){

                free(final_dir);
                free(final_file);
                errno = EISDIR;
                return NULL;
            }

            final_file->offset = 0;
            final_file->volumin = pvolume;
            final_file->size = dir_file.size;
            final_file->first_cluster = dir_file.first_cluster;
            final_file->actual_cluster = dir_file.first_cluster;
            strcpy(final_file->name, dir_file.name);

            break;
        }

        flag = dir_read(final_dir, &dir_file);
    }

    if (flag == 1){

        errno = ENOENT;
        return NULL;
    }
    else if (flag == -1){

        return NULL;
    }

    free(final_dir);
    
    return final_file;
}


//     struct SFN * root_dir = calloc(pvolume->num_of_files_root_dir, sizeof(struct SFN));

//     if (root_dir == NULL){

//         errno = ENOMEM;
//         return NULL;
//     }

//     if (-1 == disk_read(pvolume->disk, pvolume->bef_data_size - pvolume->root_dir_size, root_dir, pvolume->root_dir_size)){

//         free(root_dir);
//         return NULL;
//     }

//     struct file_t * file = calloc(1, sizeof(struct file_t));

//     if (file == NULL){

//         free(root_dir);
//         errno = ENOMEM;
//         return NULL;
//     }

//     for (uint32_t i = 0; i < pvolume->num_of_files_root_dir; ++i){

//         if (*((uint8_t*)(root_dir + i)) == UNALLOCATED || *((uint8_t*)(root_dir + i)) == DELETED){
//             continue;
//         }

//         convert_record_name((root_dir + i)->filename, (root_dir + i)->ext, file->name);
        
//         if (0 == own_strcmp(file_name, (const char*)file->name)){

//             if ((root_dir + i)->file_attributes.volume_label || (root_dir + i)->file_attributes.directory){

//                 free(root_dir);
//                 free(file);
//                 errno = EISDIR;
//                 return NULL;
//             }

//             file->volumin = pvolume;
//             file->offset = 0;
//             file->size = (root_dir + i)->size;
//             file->first_cluster = FIRST_CLUSTER((root_dir + i)->high_order_address_of_first_cluster, (root_dir + i)->low_order_address_of_first_cluster);
//             file->actual_cluster = file->first_cluster;

//             free(root_dir);
//             return file;
//         }
//         else{
//             continue;
//         }
//     }

//     free(root_dir);
//     free(file);
//     errno = ENOENT;
//     return NULL;
// }

int own_strcmp(const char * file_name1, const char * file_name2){

    if (file_name1 == NULL || file_name2 == NULL){

        return -2;
    }

    uint32_t size1 = strlen(file_name1);
    uint32_t size2 = strlen(file_name2);

    for (uint32_t i = 0; i < (size1 < size2 ? size1 : size2); ++i){

        if (toupper(file_name1[i]) > toupper(file_name2[i])){
            return 1;
        }
        else if (toupper(file_name1[i]) < toupper(file_name2[i])){
            return -1;
        }
    }

    if (size1 < size2){
        return -1;
    }
    else if (size1 > size2){
        return 1;
    }

    return 0;
}

int convert_record_name(const uint8_t * filename, const uint8_t * ext, char * name){

    if (filename == NULL || ext == NULL || name == NULL){
        return -1;
    }

        int32_t j;
        for (j = 0; j < FILE_NAME; j++){

            if (filename[j] == ' '){
                break;
            }
            
            name[j] = filename[j];
        }

        name[j] = '.';

        int32_t k;
        for (k = 0; k < FILE_EXT; k++){

            if (ext[k] == ' '){
                break;
            }
            
            name[j + 1 + k] = ext[k];
        }

        if (k > 0){
            name[j + 1 + k] = '\0';
        }
        else{
            name[j] = '\0';
        }

        return 0;
}

int file_close(struct file_t* stream){

    if (stream == NULL){

        errno = EFAULT;
        return -1;
    }

    free(stream);
    return 0;
}

size_t file_read(void *ptr, size_t size, size_t nmemb, struct file_t *stream){

    if (stream == NULL){

        errno = EFAULT;
        return -1;
    }

    if (stream->offset == stream->size || ptr == NULL){

        return 0;
    }

    uint32_t cluster_size = stream->volumin->bytes_per_sector * stream->volumin->cluster_size;
    uint8_t * cluster_data = calloc(1, cluster_size);

    if (cluster_data == NULL){

        errno = ENOMEM; // EFAULT before
        return -1;
    }

    size_t loaded_memb = 0;
    size_t size_to_read = size * nmemb;
    size_t rem_size_to_read = size * nmemb;

    if (size_to_read > stream->size - stream->offset){

        size_to_read = stream->size - stream->offset;
        rem_size_to_read = size_to_read;
    }

    uint32_t intern_offset, avail_bytes_cluster;

    do{

        if ((stream->actual_cluster - 2u) * stream->volumin->cluster_size >= stream->volumin->num_of_sectors - stream->volumin->bef_data_size){
            free(cluster_data);
            errno = ENXIO;
            return -1;
        }

        if (-1 == disk_read(stream->volumin->disk, stream->volumin->bef_data_size + (stream->actual_cluster - 2) * stream->volumin->cluster_size, cluster_data, stream->volumin->cluster_size)){

            free(cluster_data);
            return -1;
        }

        intern_offset = stream->offset % cluster_size;
        avail_bytes_cluster = cluster_size - intern_offset;

        if (rem_size_to_read <= avail_bytes_cluster){
            memcpy((uint8_t*)ptr + size_to_read - rem_size_to_read, cluster_data + intern_offset, rem_size_to_read);
            loaded_memb = size_to_read / size;
            stream->offset += rem_size_to_read;

            if (stream->offset % cluster_size == 0){

                stream->actual_cluster = stream->volumin->clusters_indexes[stream->actual_cluster];
            }

            break;
        }
        
        memcpy((uint8_t*)ptr + size_to_read - rem_size_to_read, cluster_data + intern_offset, avail_bytes_cluster);
        rem_size_to_read -= avail_bytes_cluster;
        loaded_memb = (size_to_read - rem_size_to_read) / size;
        stream->offset += avail_bytes_cluster;
        stream->actual_cluster = stream->volumin->clusters_indexes[stream->actual_cluster];

    }while(stream->actual_cluster != LAST_CLUSTER);

    free(cluster_data);

    if (loaded_memb > 0){

        return loaded_memb;
    }
    else{

        return size_to_read - rem_size_to_read;
    }

    return 0;
}

int32_t file_seek(struct file_t* stream, int32_t offset, int whence){

    if (stream == NULL){

        errno = EFAULT;
        return -1;
    }

    if (whence == 0){

        if (offset < 0 || offset > (int32_t)stream->size){

            errno = ENXIO;
            return -1;
        }
        else{
            stream->offset = (uint32_t)offset;
        }
    }
    else if (whence == 1){

        if ((int32_t)stream->offset + offset > (int32_t)stream->size || (int32_t)stream->offset + offset < 0){

            errno = ENXIO;
            return -1;
        }
        else{
            stream->offset = stream->offset + offset;
        }
    }
    else if (whence == 2){

        if (offset > 0 || (int32_t)stream->size + offset < 0){

            errno = ENXIO;
            return -1;
        }
        else{
            stream->offset = stream->size + offset;
        }
    }
    else{

        errno = EINVAL;
        return -1;
    }

    stream->actual_cluster = stream->first_cluster;

    for (uint32_t i = 0; i < stream->offset / (stream->volumin->bytes_per_sector * stream->volumin->cluster_size); ++i){

        stream->actual_cluster = stream->volumin->clusters_indexes[stream->actual_cluster];
    }

    return stream->offset;
}

struct dir_t* dir_open(struct volume_t* pvolume, const char* dir_path){

    if (pvolume == NULL || dir_path == NULL){

        errno = EFAULT;
        return NULL;
    }

    if (strlen(dir_path) == 0){

        errno = ENOENT;
        return NULL;
    }

    struct dir_entry_t file_info;
    struct file_t temp_file;
    struct dir_t_node * search_path = NULL; 
    struct dir_t * dir = dir_tree_push(&search_path, pvolume->num_of_files_root_dir * sizeof(struct SFN));

    if (dir == NULL){

        errno = ENOMEM;
        return NULL;
    }

    if (-1 == disk_read(pvolume->disk, pvolume->boot_size + pvolume->sects_per_fat * pvolume->num_of_fats, dir->current_dir, pvolume->root_dir_size)){

        dir_tree_free(&search_path);
        return NULL;
    }

    char * dir_path_copy = calloc(1, strlen(dir_path) + 1);

    if (dir_path_copy == NULL){

        dir_tree_free(&search_path);
        errno = ENOMEM;
        return NULL;
    }

    strcpy(dir_path_copy, dir_path);
    dir_path_copy[strlen(dir_path)] = '\0';

    int32_t flag = 0;
    char * filename = strtok(dir_path_copy, "\\");

    while(filename != NULL){

        if (strcmp(filename, ".") == 0){

            continue;
        }

        if (strcmp(filename, "..") == 0){

            dir = dir_tree_pop(&search_path);
            free(dir);

            if (search_path == NULL){

                //dir_tree_free(search_path);
                free(dir_path_copy);
                errno = ENOENT; // good?
                return NULL;
            }

            dir = dir_tree_pop(&search_path);
            continue;
        }

        flag = dir_read(dir, &file_info);

        while (flag == 0){

            if (own_strcmp(file_info.name, filename) == 0){

                printf("file: %s\n", filename);
                printf("file ss: %s\n", file_info.name);
                if (file_info.is_directory == 0){

                    dir_tree_free(&search_path);
                    free(dir_path_copy);
                    errno = ENOTDIR;
                    return NULL;
                }

                dir = dir_tree_push(&search_path, file_info.size);

                if (dir == NULL){

                    dir_tree_free(&search_path);
                    free(dir_path_copy);
                    errno = ENOMEM;
                    return NULL;
                }

                temp_file.offset = 0;
                temp_file.volumin = pvolume;
                temp_file.size = file_info.size;
                temp_file.first_cluster = file_info.first_cluster;
                temp_file.actual_cluster = file_info.first_cluster;
                strcpy(temp_file.name, file_info.name);


                if (file_read(dir->current_dir, file_info.size, 1, &temp_file) <= 0){

                    dir_tree_free(&search_path);
                    free(dir_path_copy);
                    return NULL;
                }
                else{

                    dir->index_record = 0;
                    dir->num_of_records = file_info.size / sizeof(struct SFN);

                    break;
                }
            }

            flag = dir_read(dir, &file_info);
        }

        if (flag == 1){

            dir_tree_free(&search_path);
            free(dir_path_copy);
            errno = ENOENT;
            return NULL;
        }
        else if (flag == -1){

            free(dir_path_copy);
            dir_tree_free(&search_path);
            return NULL;
        }

        filename = strtok(NULL, "\\");
    }

    free(dir_path_copy);
    dir = dir_tree_pop(&search_path);
    dir_tree_free(&search_path);

    return dir;
}

struct dir_t * dir_tree_push(struct dir_t_node ** head, uint32_t dir_size){

    if (head == NULL){

        return NULL;
    }

    struct dir_t_node * new_dir_node = calloc(1, sizeof(struct dir_t_node));

    if (new_dir_node == NULL){

        return NULL;
    }

    new_dir_node->dir = calloc(1, sizeof(struct dir_t));

    if (new_dir_node->dir == NULL){

        free(new_dir_node);
        return NULL;
    }

    new_dir_node->dir->current_dir = calloc(1, dir_size);

    if (new_dir_node->dir->current_dir == NULL){

        free(new_dir_node->dir);
        free(new_dir_node);
        return NULL;
    }

    new_dir_node->dir->index_record = 0;
    new_dir_node->dir->num_of_records = dir_size / sizeof(struct SFN);

    if (*head == NULL){

        new_dir_node->prev_dir = NULL;
    }
    else{

        new_dir_node->prev_dir = *head;
    }

    *head = new_dir_node;

    return (*head)->dir;
}

struct dir_t * dir_tree_pop(struct dir_t_node ** head){

    if (head == NULL || *head == NULL || (*head)->dir == NULL){ // not sure if head_dir needed

        return NULL;
    }

    struct dir_t * actual = (*head)->dir;
    struct dir_t_node * now_head = *head;
    *head = (*head)->prev_dir;
    free(now_head);
    
    return actual;
}

int dir_tree_free(struct dir_t_node ** head){

    if (head == NULL || *head == NULL){

        return 1;
    }

    struct dir_t_node * actual_node;

    while(*head != NULL){

        free((*head)->dir->current_dir);
        free((*head)->dir);
        actual_node = *head;
        *head = (*head)->prev_dir;
        free(actual_node);
    }

    return 0;
}

int dir_read(struct dir_t* pdir, struct dir_entry_t* pentry){

    if (pdir == NULL || pentry == NULL){

        errno = EFAULT;
        return -1;
    }
    else if(pdir->current_dir == NULL){

        errno = EIO;
        return -1;
    }
    else if (pdir->index_record > pdir->num_of_records){

        errno = ENXIO;
        return -1;
    }

    for (; pdir->index_record < pdir->num_of_records; pdir->index_record++){

        if (*((uint8_t*)(pdir->current_dir + pdir->index_record)) != UNALLOCATED && *((uint8_t*)(pdir->current_dir + pdir->index_record)) != DELETED && !(pdir->current_dir + pdir->index_record)->file_attributes.volume_label){
            
            convert_record_name((pdir->current_dir + pdir->index_record)->filename, (pdir->current_dir + pdir->index_record)->ext, pentry->name);
            pentry->size = (pdir->current_dir + pdir->index_record)->size;
            pentry->is_archived = (pdir->current_dir + pdir->index_record)->file_attributes.archive;
            pentry->is_readonly = (pdir->current_dir + pdir->index_record)->file_attributes.read_only;
            pentry->is_system = (pdir->current_dir + pdir->index_record)->file_attributes.system_file;
            pentry->is_hidden = (pdir->current_dir + pdir->index_record)->file_attributes.hidden_file;
            pentry->is_directory = (pdir->current_dir + pdir->index_record)->file_attributes.directory;
            pentry->first_cluster = FIRST_CLUSTER((pdir->current_dir + pdir->index_record)->high_order_address_of_first_cluster, (pdir->current_dir + pdir->index_record)->low_order_address_of_first_cluster);
            pdir->index_record++;

            return 0;
        }
    }

    return 1;
}

int dir_close(struct dir_t* pdir){

    if (pdir == NULL){

        errno = EFAULT;
        return -1;
    }

    free(pdir->current_dir);
    free(pdir);
    return 0;
}
