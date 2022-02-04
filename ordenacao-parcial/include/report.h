#ifndef REPORT_H
#define REPORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct report Report;

#include "partial_sorting.h"

/**
 * @brief Creates a Report.  
 * @param algorithm It's the algorithm name which will sorted k numbers.
 * @param original_size It is the size of array which will be sorted. 
 * @param k The quantity of numbers which will be sorted.
 * @return Return a Report. 
 */
Report* create_report(int k, char* algorithm, int original_size);

/**
 * @brief Frees an report from the memory.
 * @param report Report which will be freed.
 */
void free_report(Report* report);

/**
 * @brief Increments in 1 unity the report's field 'comparation'.
 * @param report Report which will have your field incremented.
 */
void increment_comparation(Report* report);

/**
 * @brief Increments in 1 unity the report's field 'swap'.
 * @param report Report which will have your field incremented.
 */
void increment_swap(Report* report);

/**
 * @brief Sets a new value in the field 'time'.
 * @param report Report which will have your field setted.
 * @param time New time value.
 */
void set_time(Report* report, double time);

/**
 * @brief Inserts an element in the report's array.
 * @param report Report which will have an element inserted in your array.
 * @param element Element which will be inserted.
 */
void insert_element_topK(Report* report, int element);

/**
 * @brief Fills the report's array with the top K elements from original array.
 * @param report Report which will be your array filled.
 * @param array Original array.
 * @param is_heap Boolean parameter to identify 
 */
void fill_array_topK(Report* report, Array* array, int is_heap);

void print_statistics(Report* report);

void print_k_elements(Report* report);

void print_date(Report* report, char* fileName);

#endif
