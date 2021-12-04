#ifndef SORT_H_
#define SORT_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* create_array(int length);

void free_array(int* array);

void print_array(int* array, int length);

void bubble_sort(int* array, int length);

void selection_sort(int* array, int length);

void insertion_sort(int* array, int length);

void shell_sort(int* array, int length);

void quick_sort(int* array, int length);

int is_sorted(int* array, int length);

#endif
