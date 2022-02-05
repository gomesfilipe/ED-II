#ifndef IO_H
#define IO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "partial_sorting.h"
#include "report.h"

/**
 * @brief Breaks the command line input in some variables.
 * @param argv Array of arguments.
 * @param control_keys Dispatch table to control [-123sieqh].
 * @param k Represents the quantity of elements that will be sorted.
 * @param fileName Path to input file.
 */
void split(char** argv, int* control_keys, int* k, char* fileName);

/**
 * @brief This function read the input's file and calls the functions which creates
 * the array of numbers.
 * @param fileName Path to input file
 * @return Array filled with input's numbers.
 */
Array* read_file(char* fileName);

/**
 * @brief This function chooses which dates will be printed on the screen.
 * @param report Date Structure that contains information that will be printed on the screen.
 * @param control_keys Dispatch table to control [-123sieqh].
 * @param fileName The input file's name.
 */
void print_output(Report* report, int* control_keys, char* fileName);

/**
 * @brief Choose which sorting will be made according to the number passed at command line.
 * @param array Array which will be partial sorted.
 * @param k Quantity of element which will be sorted.
 * @param control_keys Dispatch table to control [-123sieqh].
 * @param fileName Path to input file.
 */
void build_report(Array* array, int k, int* control_keys, char* fileName);

#endif
