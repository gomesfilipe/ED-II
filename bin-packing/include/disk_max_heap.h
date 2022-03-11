#ifndef DISK_MAX_HEAP_H_
#define DISK_MAX_HEAP_H_

#include <stdio.h>
#include <stdlib.h>
#include "disk.h"
#include "file.h"
#include "file_array.h"

typedef struct heap Heap;

Heap* create_heap(FileArray* fileArray);

void free_heap(Heap* heap);

void print_heap(Heap* heap);

void insert_disk_in_heap(Heap* heap, Disk* disk);

Disk* remove_max_disk_in_heap(Heap* heap);

#endif
