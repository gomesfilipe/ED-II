#ifndef DISK_MAX_HEAP_H_
#define DISK_MAX_HEAP_H_

#include <stdio.h>
#include <stdlib.h>
#include "disk.h"
#include "file.h"
#include "file_array.h"

typedef struct heap Heap;

/**
 * @brief Creates a empty maximum heap.
 * @param fileArray File array to know the size of heap.
 * @return Pointer to Heap. 
 */
Heap* create_heap(FileArray* fileArray);

/**
 * @brief Frees a heap from the memory.
 * @param heap Heap that will be freed.
 */
void free_heap(Heap* heap);

/**
 * @brief Prints on the screen the heap elements.
 * @param heap Heap that will be printed.
 */
void print_heap(Heap* heap);

/**
 * @brief Gets the size's heap.
 * @param heap Heap that his size will be got.
 * @return Size's heap.
 */
int get_size_heap(Heap* heap);

/**
 * @brief Gets the length's heap.
 * @param heap Heap that his length will be got.
 * @return Length's heap.
 */
int get_length_heap(Heap* heap);

/**
 * @brief Inserts a disk in the heap.
 * @param heap Heap that will have an element inserted.
 * @param disk Disk that will be inserted.
 */
void insert_disk_in_heap(Heap* heap, Disk* disk);

/**
 * @brief Removes the heap's first element. 
 * @param heap Heap that will be an element removed.
 * @return Pointer to the removed Disk. 
 */
Disk* remove_max_disk_in_heap(Heap* heap);

/**
 * @brief Get the first disk in the heap.
 * @param heap Heap that will be his first disk got.
 * @return Pointer to the first Disk. 
 */
Disk* get_first_disk_in_heap(Heap* heap);

#endif
