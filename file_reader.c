#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdint.h>
#include <time.h>
#include "file_reader.h"
#define SECTOR_SIZE 512
#define VOLUMIN_SIGNATURE 0xAA55 // Value from resources, task author suggests 0x55AA BIG vs. LITTLE endian?
#define LAST_CLUSTER(index) (index ^ 0xfff) // looking for the file's last cluster index


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





    free(boot_sec);
    return 0;
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


    return 0;
}

int file_close(struct file_t* stream){


    return 0;
}

size_t file_read(void *ptr, size_t size, size_t nmemb, struct file_t *stream){


    return 0;
}

int32_t file_seek(struct file_t* stream, int32_t offset, int whence){


    return 0;
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
