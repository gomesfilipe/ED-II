#ifndef FILE_ARRAY_H_
#define FILE_ARRAY_H_

#include <stdio.h>
#include <stdlib.h>
#include "file.h"

typedef struct fileArray FileArray;
/**
 * @brief Create a file array object.
 * @param size File Array's size.
 * @return Pointer to a FileArray. 
 */
FileArray* create_file_array(int size);

/**
 * @brief Frees a file array from the memory.
 * @param fileArray File array that will be freed. The file objects are freed too.
 */
void free_file_array(FileArray* fileArray);

/**
 * @brief Prints a file array on the screen.
 * @param file File array that will be printed.
 */
void print_file_array(FileArray* fileArray);

/**
 * @brief Inserts a file in a file array.  
 * @param fileArray File array that will have a file inserted.
 * @param file File that will be inserted.
 * @return SUCCESS (1), if have enough space.
 * @return FAIL (0), if don't have enough space.
 */
int insert_file_in_array(FileArray* fileArray, File* file);

/**
 * @brief Creates a filled file array according a text file.
 * @param fileName File name of the text file which contains the datas about all files that will be inserted.
 * @return Pointer to a filled file array. 
 */
FileArray* reader(char* fileName);

/**
 * @brief Sorts in a descending order a file array using quick sort algorithm.
 * @param fileArray File array that will be sorted.
 */
void sort_array(FileArray* fileArray);

/**
 * @brief Gets the file array's size.
 * @param fileArray File array that his size will be got.
 * @return File array's size.
 */
int get_size_array(FileArray* fileArray);

/**
 * @brief Gets the file array's length.
 * @param fileArray File array that his length will be got.
 * @return File array's length.
 */
int get_length_array(FileArray* fileArray);

/**
 * @brief Get the file in a file array at a index.
 * @param fileArray File Array.
 * @param index Index file that will be got.
 * @return Pointer to a file.
 * @return NULL, if index is invalid. 
 */
File* get_file_at_index(FileArray* fileArray, int index);

#endif
