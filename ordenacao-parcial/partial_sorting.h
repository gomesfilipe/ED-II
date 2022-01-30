#ifndef PARTIAL_SORTING_H
#define PARTIAL_SORTING_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct array Array;

/**
 * @brief Constructor of an array object.
 * @param size Array's size.
 * @return Returns an empty array. 
 */
Array* create_array(int size);

/**
 * @brief Frees the array from memory.
 * @param array Array which will be freed.
 */
void free_array(Array* array);

/**
 * @brief This function gets the Array's length.
 * @param length Array's length.
 * @return Returns Array's length.
 */
int get_length(Array* array);

/**
 * @brief Gets the pointer to array of integers.
 * @param Array Array which will have your array of integers got.
 * @return Returns the pointer to array of integers. 
 */
int* get_array(Array* array);

/**
 * @brief Sorts the first k elements by selection sort algorithm.
 * @param array Array which will be partial sorted.
 * @param k Number of elements which will be sorted.
 */
void partial_selection_sort(Array* array, int k);

/**
 * @brief Sorts the first k elements by insertion sort algorithm.
 * @param array Array which will be partial sorted.
 * @param k Number of elements which will be sorted.
 */
void partial_insertion_sort(Array* array , int k);

/**
 * @brief Sorts the first k elements by shell sort algorithm.
 * @param array Array which will be partial sorted.
 * @param k Number of elements which will be sorted.
 */
void partial_shell_sort(Array* array, int k);

/**
 * @brief Sorts the first k elements by quick sort algorithm.
 * @param array Array which will be partial sorted.
 * @param k Number of elements which will be sorted.
 */
void partial_quick_sort(Array* array, int k);

/**
 * @brief Sorts the first k elements by heap sort algorithm.
 * @param array Array which will be partial sorted.
 * @param k Number of elements which will be sorted.
 */
void partial_heap_sort(Array* array, int k);

void fill_array(Array* array);

void print_array(Array* array);

#endif
