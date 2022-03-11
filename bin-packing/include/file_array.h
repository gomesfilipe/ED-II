#ifndef FILE_ARRAY_H_
#define FILE_ARRAY_H_

#include <stdio.h>
#include <stdlib.h>
#include "file.h"

typedef struct fileArray FileArray;

FileArray* create_file_array(int size);

void free_file_array(FileArray* fileArray);

void print_file_array(FileArray* fileArray);

void insert_file(FileArray* fileArray, File* file);

FileArray* reader(char* fileName);

void sort_array(FileArray* fileArray);

#endif
