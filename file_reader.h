#ifndef F_READER_H
#define F_READER_H

#include <stdio.h>
#include <stdint.h>
#include <time.h>

struct BPB{
    uint8_t assembly_inst[3];
    uint64_t OEM;
    uint16_t b_per_sect;
    uint8_t sects_per_clust;
    uint16_t reserved_sects;
    uint8_t num_of_fats;
    uint16_t max_num_of_root_dir;
    uint16_t num_of_sects_in_fsys;
    uint8_t media_type;
    uint16_t sects_per_fat;
    uint16_t sects_per_track;
    uint16_t num_of_heads;
    uint32_t num_of_sects_bef_start;
    uint32_t sec_num_of_sects_in_fsys;
} __attribute__((__packed__));

struct extended_BPB{
    struct BPB BPB_info;
    uint8_t drive_number;
    uint8_t not_used;
    uint8_t sign_to_validate_next;
    uint8_t vol_ser_num[4];
    uint8_t vol_label[11];
    uint8_t file_sys_type[8];
    uint8_t not_used_2[448];
    uint16_t sign_value;
} __attribute__((__packed__));

union mod_cr_time{

    uint16_t time;

    struct{
        uint16_t sec : 5;
        uint16_t min : 6;
        uint16_t hour : 5;
    };
} __attribute__((__packed__));

union mod_cr_date{

    uint16_t date;

    struct{
        uint16_t day : 5;
        uint16_t month : 4;
        uint16_t year : 7;
    };
} __attribute__((__packed__));

union file_attrs{

    uint8_t file_attributes;

    struct{
        uint8_t read_only : 1;
        uint8_t hidden_file : 1;
        uint8_t system_file : 1;
        uint8_t volume_label : 1;
        uint8_t directory : 1;
        uint8_t archive : 1;
        uint8_t bit7 : 1;
        uint8_t bit8 : 1;
    };
} __attribute__((__packed__));

struct SFN{
    uint8_t filename[8];
    uint8_t ext[3];
    union file_attrs file_attributes;
    uint8_t reserved;
    uint8_t file_creation_time;
    union mod_cr_time creation_time;
    union mod_cr_date creation_date;
    uint16_t access_date;
    uint16_t high_order_address_of_first_cluster;
    union mod_cr_time modified_time;
    union mod_cr_date modified_date;
    uint16_t low_order_address_of_first_cluster;
    uint32_t size;
} __attribute__((__packed__));

struct disk_t{
    FILE * file;
    uint32_t many_sectors;
} __attribute__((__packed__));

struct volume_t{

    struct disk_t * disk;
    uint16_t bytes_per_sector;
    uint16_t boot_size;
    uint32_t fat_size;
    uint8_t sects_per_fat;
    uint8_t num_of_fats;
    uint8_t cluster_size;
    uint16_t num_of_files_root_dir;
    uint16_t root_dir_size;
    uint16_t bef_data_size;
    uint32_t num_of_sectors;
    uint8_t type;
    uint16_t * clusters_indexes;
    
} __attribute__((__packed__));

struct file_t{

    struct volume_t * volumin;
    uint32_t offset;
    uint32_t size;
    uint16_t first_cluster;
    uint16_t actual_cluster;
    char name[13];  // could be uint8_t* but small problem with using strcmp() :)

} __attribute__((__packed__));

struct dir_t{

    struct SFN * current_dir;
    uint16_t num_of_records;
    uint16_t index_record;

} __attribute__((__packed__));

struct dir_entry_t{

    uint32_t size;
    char name[13];
    uint8_t is_archived : 1;
    uint8_t is_readonly : 1;
    uint8_t is_system : 1;
    uint8_t is_hidden : 1;
    uint8_t is_directory : 1;

} __attribute__((__packed__));

struct disk_t* disk_open_from_file(const char* volume_file_name);
int disk_read(struct disk_t* pdisk, int32_t first_sector, void* buffer, int32_t sectors_to_read);
int disk_close(struct disk_t* pdisk);
struct volume_t* fat_open(struct disk_t* pdisk, uint32_t first_sector);
int fat_close(struct volume_t* pvolume);
struct file_t* file_open(struct volume_t* pvolume, const char* file_name);
int file_close(struct file_t* stream);
size_t file_read(void *ptr, size_t size, size_t nmemb, struct file_t *stream);
int32_t file_seek(struct file_t* stream, int32_t offset, int whence);
struct dir_t* dir_open(struct volume_t* pvolume, const char* dir_path);
int dir_read(struct dir_t* pdir, struct dir_entry_t* pentry);
int dir_close(struct dir_t* pdir);
int convert_record_name(const uint8_t * filename, const uint8_t * ext, char * name);

#endif