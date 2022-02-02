#ifndef REPORT_H
#define REPORT_H

#include <stdio.h>
#include <stdlib.h>

typedef struct report Report;

#include "partial_sorting.h"


Report* create_report(int k);

void free_report(Report* report);

void increment_comparation(Report* report);

void increment_swap(Report* report);

void set_time(Report* report, double time);

void insert_element_topK(Report* report, int element);

void fill_array_topK(Report* report, Array* array, int is_heap);

void print_report(Report* report);

#endif
