#ifndef DISK_H_
#define DISK_H_

#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "file_array.h"

typedef struct disk Disk;

/**
 * @brief Create a disk object.
 * @return Pointer to a disk object. 
 */
Disk* create_disk();

/**
 * @brief Frees a disk from the memory.
 * @param disk Disk that will be freed.
 */
void free_disk(Disk* disk);

/**
 * @brief Prints a disk on the screen.
 * @param disk Disk that will be printed.
 */
void print_disk(Disk* disk);

/**
 * @brief Gets the disk's capacity.
 * @param disk Disk that his capacity will be got.
 * @return Disk's capacity.
 */
int get_capacity(Disk* disk);

/**
 * @brief Gets the disk's free space.
 * @param disk Disk that his free space will be got.
 * @return Disk's free space.
 */
int get_freeSpace(Disk* disk);

int has_space(Disk* disk, File* file);

/**
 * @brief Inserts a file in a disk, decreasing his free space. 
 * @param disk Disk that will have a file inserted.
 * @param file File that will be inserted.
 * @return SUCCESS (1), if have enough space.
 * @return FAIL (0), if don't have enough space.
 */
int insert_file_in_disk(Disk* disk, File* file);

#endif