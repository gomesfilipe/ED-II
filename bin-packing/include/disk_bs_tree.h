#ifndef DISK_BS_TREE_H_
#define DISK_BS_TREE_H_

#include <stdio.h>
#include <stdlib.h>
#include "disk.h"
#include "file.h"
#include "file_array.h"

typedef struct tree Tree;

/**
 * @brief Create a tree with a disk.
 * @param disk Disk's root node.
 * @return Pointer to a tree. 
 */
Tree* create_tree(Disk* disk);

/**
 * @brief Checks if a tree is empty.
 * @param tree Tree that will be checked.
 * @return 1, if is empty.
 * @return 0, if isn't empty.
 */
int is_empty_tree(Tree* tree);

/**
 * @brief Checks if a tree is a leaf node.
 * @param tree Tree that will be checked.
 * @return 1, if is a leaf node.
 * @return 0, if isn't a leaf node.
 */
int is_leaf_node(Tree* tree);

/**
 * @brief This function release a tree from memory.
 * @param tree Tree that will be relesed.
 */
void free_tree(Tree* tree);

/**
 * @brief Prints a tree on the screen. Prints the root, left child and right child, respectvely.
 * @param tree Tree that will be printed.
 */
void print_tree(Tree* tree);

/**
 * @brief Inserts a disk in the tree.
 * @param tree Tree that will be a disk inserted.
 * @param disk Disk that will be inserted.
 * @return Pointer to the tree's root node. 
 */
Tree* insert_disk_in_tree(Tree* tree, Disk* disk);

/**
 * @brief Search the disk which contains the smallest enough free space for a given file.
 * At the end of this function, the disk will be setted on "min" parameter. 
 * @param tree Tree that will be searched.
 * @param file File to cheking if a node contains free space or not.
 * @param min The minimum disk will be stored in this parameter. If there isn't a mininum disk, NULL will be stored.
 */
void search_min_disk_in_tree(Tree* tree, File* file, Disk** min);


/**
 * @brief This function removes the smallest disk in free space from the tree.
 * @param tree Tree that will have a disk removed.
 * @param key Parameter used to know which disk will be removed.
 * @param Disk Address which contaion the disk removed
 * @return Tree without the smallest disk in free space.
 */
Tree* remove_min_disk_in_tree(Tree* tree, int key, Disk** removed);

#endif
