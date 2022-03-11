#ifndef FILE_H_
#define FILE_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct file File;

File* create_file(int size);

void free_file(File* file);

void print_file(File* file);

int get_size(File* file);

#endif
