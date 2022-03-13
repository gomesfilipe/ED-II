#ifndef DISK_BS_TREE_H_
#define DISK_BS_TREE_H_

#include <stdio.h>
#include <stdlib.h>
#include "disk.h"
#include "file.h"
#include "file_array.h"

typedef struct tree Tree;

Tree* create_tree(Disk* disk);

int is_empty_tree(Tree* tree);

int is_leaf_node(Tree* tree);

void free_tree(Tree* tree);

void print_tree(Tree* tree);

Tree* insert_disk_in_tree(Tree* tree, Disk* disk);

void search_min_disk_in_tree(Tree* tree, File* file, Disk** min);

Tree* remove_min_disk_in_tree(Tree* tree, int key, Disk** removed);

#endif
