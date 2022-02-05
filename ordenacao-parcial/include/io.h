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
 * @param alg Represents the algorithm's character.
 * @param report Represents the report's character.
 * @param k Represents the quantity of elements that will be sorted.
 * @param fileName Path to input file.
 */
void split(char** argv, char* alg, char* report, int* k, char* fileName);

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
 * @param number Parameter that will determinete which information will be displayed.
 * @param fileName The input file's name.
 */
void print_output(Report* report, int number, char* fileName);

/**
 * @brief Choose which sorting will be made according to the number passed at command line.
 * @param array Array which will be partial sorted.
 * @param k Quantity of element which will be sorted.
 * @param number Number of report.
 * @param alg Represents the algorithm's character. 
 * @param fileName Path to input file.
 */
void build_report(Array* array, int k, int number, char alg, char* fileName);

#endif
