#ifndef IO_H
#define IO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str.h"

String* read_txt(char* fileName);

void split(char** argv, int* control_keys, char* fileName, int* context, char* query);

#endif
