#ifndef BEST_FIT_H_
#define BEST_FIT_H_

#include <stdio.h>
#include <stdlib.h>
#include "disk.h"
#include "disk_bs_tree.h"
#include "file.h"
#include "file_array.h"

/**
 * @brief Executes the best fit in the sequence of array elements.
 * @param fileArray File array.
 * @return Quantity of disks.
 */
int best_fit(FileArray* fileArray);

/**
 * @brief Executes the best fit with the file array sorted.
 * @param fileArray File array.
 * @return Quantity of disks.
 */
int best_fit_descending(FileArray* fileArray);

#endif
