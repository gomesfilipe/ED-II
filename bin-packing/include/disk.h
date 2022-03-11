#ifndef DISK_H_
#define DISK_H_

#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "file_array.h"

typedef struct disk Disk;

Disk* create_disk();

void free_disk(Disk* disk);

void print_disk(Disk* disk);

int get_capacity(Disk* disk);

int get_freeSpace(Disk* disk);

void insert_file_in_disk(Disk* disk, File* file);

#endif