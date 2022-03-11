#ifndef WORST_FIT_H_
#define WORST_FIT_H_

#include <stdio.h>
#include <stdlib.h>
#include "disk.h"
#include "disk_max_heap.h"
#include "file.h"
#include "file_array.h"

int worst_fit_in_order(FileArray* fileArray);

int worst_fit_descending(FileArray* fileArray);

#endif
