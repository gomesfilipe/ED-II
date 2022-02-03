#ifndef IO_H
#define IO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "partial_sorting.h"
#include "report.h"


void split(char** argv, char* alg, char* report, int* k, char* fileName);
 
Array* read_file(char* fileName);

void build_report(Array* array, int k, int number, char alg, char* fileName);

#endif
