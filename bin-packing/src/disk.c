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
    printf("%d / %d\n", disk->freeSpace, disk->capacity);
}

int get_capacity(Disk* disk) {
    return disk->capacity;
}

int get_freeSpace(Disk* disk) {
    return disk->freeSpace;
}

int insert_file_in_disk(Disk* disk, File* file) {
    if(get_size(file) > disk->freeSpace) return FAIL;

    disk->freeSpace -= get_size(file);
    return SUCCESS;
}
