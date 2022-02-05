#ifndef REPORT_H
#define REPORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct report Report;

#include "partial_sorting.h"

/**
 * @brief Creates a Report that contains information that will be displayed on the screen.  
 * @param algorithm It's the algorithm's name which will sorted the top k numbers.
 * @param original_size It's the array's size which will be sorted. 
 * @param k The quantity of numbers which will be sorted.
 * @return Return a Report. 
 */
Report* create_report(int k, char* algorithm, int original_size);

/**
 * @brief Frees a report from the memory.
 * @param report Report which will be freed.
 */
void free_report(Report* report);

/**
 * @brief Increments in 1 unity the report's field 'comparation'.
 * @param report Report which will have its field incremented.
 */
void increment_comparation(Report* report);

/**
 * @brief Increments in 1 unity the report's field 'swap'.
 * @param report Report which will have its field incremented.
 */
void increment_swap(Report* report);

/**
 * @brief Sets a new value in the field 'time'.
 * @param report Report which will have its field setted.
 * @param time New time value.
 */
void set_time(Report* report, double time);

/**
 * @brief Inserts an element in the report's array.
 * @param report Report which will have an element inserted in its array.
 * @param element Element which will be inserted.
 */
void insert_element_topK(Report* report, int element);

/**
 * @brief Fills the report's array with the top K elements from original array.
 * @param report Report which will contain the array filled.
 * @param array Original array.
 * @param is_heap Boolean parameter to identify if the algorithm that has made the sorting 
 * was parcial_heap_sort or not.
 */
void fill_array_topK(Report* report, Array* array, int is_heap);

/**
 * @brief Prints on the screen the quantity of comparations, swaps and time from sorting.
 * @param report Report generated after sorting.
 */
void print_statistics(Report* report);

/**
 * @brief Prints on the screen the top k elements from sorting.
 * @param report Report generated after sorting.
 */
void print_k_elements(Report* report);

/**
 * @brief Prints on the screen dates of sorting separated by tab.
 * @param report Report generated after sorting.
 * @param fileName Path to input file.
 */
void print_date(Report* report, char* fileName);

#endif
