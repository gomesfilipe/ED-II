#include "bst.h"

struct bst {
    int key;
    int size;
    BST* left;
    BST* right;
};

BST* create_empty_BST() {
    return NULL;
}

BST* create_BST(int key) {
    BST* bst = (BST*) malloc(sizeof(BST));
    bst->key = key;
    bst->size = 1;
    bst->left = NULL;
    bst->right = NULL;

    return bst;
}

int is_empty_BST(BST* bst) {
    return bst == NULL;
}

int get_size_BST(BST* bst) {
    if(is_empty_BST(bst)) return 0;

    return bst->size;
}

void free_BST(BST* bst) {
    if(is_empty_BST(bst)) return;

    free_BST(bst->left);
    free_BST(bst->right);
    free(bst);
}

static int max(int a, int b) {
    return a > b ? a : b;
}

int height_BST(BST* bst) {
    if(is_empty_BST(bst)) return -1;

    return  1 + max(height_BST(bst->left), height_BST(bst->right));
}

BST* insert_BST(BST* bst, int key) {
    if(is_empty_BST(bst)) {
        return create_BST(key);
    
    } else {
        if(key <= bst->key) {
            bst->size++;
            bst->left = insert_BST(bst->left, key);
        
        } else {
            bst->size++;
            bst->right = insert_BST(bst->right, key);
        }
    }

    return bst;
}

void print_BST(BST* bst) {
    printf("<");
    if(is_empty_BST(bst)) return;

    printf("%d ", bst->key);
    print_BST(bst->left);
    print_BST(bst->right);
    printf(">");
}

static void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

BST* left_rotation_BST(BST* bst) {
    BST* tmp = bst->right;
    bst->right = tmp->left;
    tmp->left = bst;
    
    bst->size = get_size_BST(bst->left) + get_size_BST(bst->right);
    tmp->size = get_size_BST(tmp->left) + get_size_BST(tmp->right);

    return tmp;
}

BST* right_rotation_BST(BST* bst) {
    BST* tmp = bst->left;
    bst->left = tmp->right;
    tmp->right = bst;

    bst->size = get_size_BST(bst->left) + get_size_BST(bst->right);
    tmp->size = get_size_BST(tmp->left) + get_size_BST(tmp->right);
    
    return tmp;
}

BST* insert_in_root_BST(BST* bst, int key) {
    if(is_empty_BST(bst)) {
        return create_BST(key);
    
    } else if(key <= bst->key) {
        bst->size++;
        bst->left = insert_in_root_BST(bst->left, key);
        bst = right_rotation_BST(bst);

    } else {
        bst->size++;
        bst->right = insert_in_root_BST(bst->right, key);
        bst = left_rotation_BST(bst);
    }

    return bst;
}
