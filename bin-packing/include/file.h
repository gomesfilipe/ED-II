#ifndef FILE_H_
#define FILE_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct file File;

/**
 * @brief Create a file object.
 * @param size File's size.
 * @return Pointer to a file object.
 */
File* create_file(int size);

/**
 * @brief Frees a file from the memory.
 * @param file File that will be freed.
 */
void free_file(File* file);

/**
 * @brief Prints a file on the screen.
 * @param file File that will be printed.
 */
void print_file(File* file);

/**
 * @brief Gets the file's size.
 * @param file File that his size will be got.
 * @return File's size.
 */
int get_size(File* file);

#endif
