#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdint.h>
#include "file_reader.h"



struct disk_t* disk_open_from_file(const char* volume_file_name){



}

int disk_read(struct disk_t* pdisk, int32_t first_sector, void* buffer, int32_t sectors_to_read){



}

int disk_close(struct disk_t* pdisk){



}

struct volume_t* fat_open(struct disk_t* pdisk, uint32_t first_sector){



}

int fat_close(struct volume_t* pvolume){



}

struct file_t* file_open(struct volume_t* pvolume, const char* file_name){



}

int file_close(struct file_t* stream){



}

size_t file_read(void *ptr, size_t size, size_t nmemb, struct file_t *stream){



}

int32_t file_seek(struct file_t* stream, int32_t offset, int whence){



}

struct dir_t* dir_open(struct volume_t* pvolume, const char* dir_path){



}

int dir_read(struct dir_t* pdir, struct dir_entry_t* pentry){



}

int dir_close(struct dir_t* pdir){



}
