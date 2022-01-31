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
 * @brief Prints the array element on stdin.
 * @param array Array which will be printed.
 */
void print_array(Array* array);

/**
 * @brief Gets the pointer to array of integers.
 * @param array Array which will have your array of integers got.
 * @return Returns the pointer to array of integers. 
 */
int* get_array(Array* array);

/**
 * @brief Gets the Array's size.
 * @param array Array which will have your size got.
 * @return Returns theArray's size. 
 */
int get_size(Array* array);

/**
 * @brief Gets the Array's length.
 * @param array Array which will have your length got.
 * @return Returns Array's length.
 */
int get_length(Array* array);

/**
 * @brief Sorts the first k elements by selection sort algorithm.
 * @param array Array which will be partial sorted.
 * @param k Number of elements which will be sorted.
 */
void partial_selection_sort(Array* array, int k);

/**
 * @brief Checks if the array is full.
 * @param array Array which will be checked.
 * @return 1 case true or 0 case false.
 */
int is_full(Array* array);

/**
 * @brief Inserts an element at the end of the array if him is not full. 
 * @param array Array which will be an element inserted.
 * @param element Element which will be inserted.
 */
void insert_element_array(Array* array, int element);

/**
 * @brief Fill an array with random numbers.
 * @param array Array which will be filled.
 */
void fill_array(Array* array);

/**
 * @brief Swap the value of two variables.
 * @param a Pointer to the first variable.
 * @param b Pointer to the second variable.
 */
void swap(int* a, int* b);

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

#endif
