#ifndef WORST_FIT_H_
#define WORST_FIT_H_

#include <stdio.h>
#include <stdlib.h>
#include "disk.h"
#include "disk_max_heap.h"
#include "file.h"
#include "file_array.h"

/**
 * @brief Executes the worst fit in the sequence of array elements.
 * @param fileArray File array.
 * @return Quantity of disks.
 */
int worst_fit_in_order(FileArray* fileArray);

/**
 * @brief Executes the worst fit with the file array sorted.
 * @param fileArray File array.
 * @return Quantity of disks.
 */
int worst_fit_descending(FileArray* fileArray);

#endif
