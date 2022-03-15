#include "../include/disk.h"

#define DISK_CAPACITY 1000000
#define SUCCESS 1
#define FAIL 0

struct disk {
    int capacity;
    int freeSpace;
};

Disk* create_disk() {
    Disk* disk = (Disk*) malloc(sizeof(Disk));
    disk->capacity = DISK_CAPACITY;
    disk->freeSpace = DISK_CAPACITY;
    return disk;
}

void free_disk(Disk* disk) {
    free(disk);
}

void print_disk(Disk* disk) {
    // printf("%d / %d\n", disk->freeSpace, disk->capacity);
    printf("%d\n", disk->freeSpace);
}

int get_capacity(Disk* disk) {
    return disk->capacity;
}

int get_freeSpace(Disk* disk) {
    return disk->freeSpace;
}

int there_is_space(Disk* disk, File* file) {
    return disk->freeSpace >= get_size(file);
}

int insert_file_in_disk(Disk* disk, File* file) {
    if(!there_is_space(disk, file)) return FAIL;

    disk->freeSpace -= get_size(file);
    return SUCCESS;
}
