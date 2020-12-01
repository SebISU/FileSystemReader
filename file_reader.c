#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include "file_reader.h"
#define UNALLOCATED 0x00
#define DELETED 0xe5
#define FILE_NAME 8
#define FILE_EXT 3
#define SECTOR_SIZE 512
#define VOLUMIN_SIGNATURE 0xAA55 // Value from resources, task author suggests 0x55AA BIG vs. LITTLE endian?
#define LAST_CLUSTER(index) (index ^ 0xffff) // looking for the file's last cluster index, fix this
#define POWER_OF_TWO(x) (!(x & (x - 1)) && x)
#define MAX_CLUSTER_SIZE 64


struct disk_t* disk_open_from_file(const char* volume_file_name){

    if (volume_file_name == NULL){

        errno = EFAULT;
        return NULL;
    }

    struct disk_t * disk = malloc(sizeof(struct disk_t));

    if (disk == NULL){

        errno = ENOMEM;
        return NULL;
    }

    if((disk->file = fopen(volume_file_name, "rb")) == NULL){

        errno = ENOENT;
        return NULL;
    }

    fseek(disk->file, 0, SEEK_END);

    disk->many_sectors = ftell(disk->file) / SECTOR_SIZE;   // what if will be 0?

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

    struct volume_t * volumin = malloc(sizeof(struct volume_t));
    struct extended_BPB * boot_sec = malloc(sizeof(struct extended_BPB));

    if (volumin == NULL){

        free(boot_sec);
        errno = ENOMEM;
        return NULL;
    }
    else if(boot_sec == NULL){

        free(volumin);
        errno = ENOMEM;
        return NULL;
    }

    if (-1 == disk_read(pdisk, first_sector, boot_sec, 1)){

        free(volumin);
        free(boot_sec);
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

    if (0 == strncmp(boot_sec->file_sys_type, "FAT12", 5)){

        volumin->type = 12;
    }
    else if (0 == strncmp(boot_sec->file_sys_type, "FAT16", 5)){

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

    for (int32_t i = 0; i < volumin->num_of_fats - 1; ++i){

        if (0 != memcmp(fats_data + i * volumin->fat_size, fats_data + (i + 1) * volumin->fat_size, volumin->fat_size)){

            errno = EINVAL;
            free(fats_data);
            free(volumin);
            free(boot_sec);
            return NULL;
        }
    }

    volumin->clusters_indexes = calloc(volumin->fat_size, sizeof(uint16_t));

    if (volumin->clusters_indexes == NULL){

        errno = EINVAL;
        free(fats_data);
        free(volumin);
        free(boot_sec);
        return NULL;
    }

    if (volumin->type == 12){

        for (int32_t i = 0; i < volumin->fat_size; ++i){

            if (i % 3 == 0){

                uint16_t value = *(fats_data + i + 1) & 0x0f;
                value <<= 8;
                *(volumin->clusters_indexes + i) = value | *(fats_data + i);
            }
            else if (i % 3 == 1){

                *(volumin->clusters_indexes + i) = 0xffff; //maybe 0 is better?
            }
            else{

                uint16_t value = *(fats_data + i);
                value <<= 4;
                *(volumin->clusters_indexes + i) = value | (*(fats_data + i - 1) >> 4);
            }
        }
    }
    else{

        for (int32_t i = 0; i < volumin->fat_size; i += 2){

            *(volumin->clusters_indexes + i/2) = *((uint16_t*)(fats_data + i));
        }
    }

    volumin->disk = pdisk;

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

    struct SFN * root_dir = calloc(pvolume->num_of_files_root_dir, sizeof(struct SFN));

    if (root_dir == NULL){

        errno = ENOMEM;
        return NULL;
    }

    if (-1 == disk_read(pvolume->disk, pvolume->boot_size + pvolume->sects_per_fat * pvolume->num_of_fats, root_dir, pvolume->root_dir_size)){

        free(root_dir);
        return NULL;
    }

    struct file_t * file = calloc(1, sizeof(struct file_t));

    if (file == NULL){

        free(root_dir);
        errno = ENOMEM;
        return NULL;
    }

    for (int32_t i = 0; i < pvolume->num_of_files_root_dir; ++i){

        if (*((uint8_t*)(root_dir + i)) == UNALLOCATED || *((uint8_t*)(root_dir + i)) == DELETED){
            continue;
        }

        int32_t j;
        for (j = 0; j < FILE_NAME; j++){

            if ((root_dir + i)->filename[j] == ' '){
                break;
            }
            
            file->name[j] = (root_dir + i)->filename[j];
        }

        file->name[j] = '.';

        int32_t k;
        for (k = 0; k < FILE_EXT; k++){

            if ((root_dir + i)->ext[k] == ' '){
                break;
            }
            
            file->name[j + 1 + k] = (root_dir + i)->ext[k];
        }

        file->name[j + 1 + k] = '\0';

        if (0 == strcmp(file_name, file->name)){

            if ((root_dir + i)->file_attributes.volume_label || (root_dir + i)->file_attributes.directory){

                free(root_dir);
                free(file);
                errno = EISDIR;
                return NULL;
            }

            file->volumin = pvolume;
            file->offset = 0;
            file->size = (root_dir + i)->size;
            file->file_attributes.file_attributes = (root_dir + i)->file_attributes.file_attributes;
            uint32_t cluster = (root_dir + i)->high_order_address_of_first_cluster << 16;   // brackets?
            cluster |= (root_dir + i)->low_order_address_of_first_cluster;
            file->first_cluster = cluster;
            file->actual_cluster = cluster;

            free(root_dir);
            return file;
        }
        else{
            continue;
        }
    }

    free(root_dir);
    free(file);
    errno = ENOENT;
    return NULL;
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

    if (ptr == NULL || stream == NULL){

        errno = EFAULT;
        return -1;
    }

    // ENXIO -> klaster z poza woluminu



    return 0;
}

int32_t file_seek(struct file_t* stream, int32_t offset, int whence){

    if (stream == NULL){

        errno = EFAULT;
        return -1;
    }
    else if (whence < 0 || 2 < whence){

        errno = EINVAL;
        return -1;
    }

    if (whence == 0 && (offset < 0 || offset > stream->size)){

        errno = ENXIO;
        return -1;
    }
    else{
        stream->offset = offset;
    }

    if (whence == 1 && (stream->offset + offset > stream->size || stream->offset + offset < 0)){

        errno = ENXIO;
        return -1;
    }
    else{
        stream->offset = stream->offset + offset;
    }

    if (whence == 2 && (offset > 0 || stream->offset + offset < 0)){

        errno = ENXIO;
        return -1;
    }
    else{
        stream->offset = stream->offset + offset;
    }

    return (int32_t)stream->offset;
}

struct dir_t* dir_open(struct volume_t* pvolume, const char* dir_path){


    return 0;
}

int dir_read(struct dir_t* pdir, struct dir_entry_t* pentry){


    return 0;
}

int dir_close(struct dir_t* pdir){


    return 0;
}
