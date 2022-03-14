#ifndef BST_H_
#define BST_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct bst BST;

BST* create_empty_BST();

BST* create_BST(int key);

int is_empty_BST(BST* bst);

void free_BST(BST* bst);

int height_BST(BST* bst);

BST* insert_BST(BST* bst, int key);

void print_BST(BST* bst);

BST* left_rotation_BST(BST* bst);

BST* right_rotation_BST(BST* bst);

BST* insert_in_root_BST(BST* bst, int key);

#endif
