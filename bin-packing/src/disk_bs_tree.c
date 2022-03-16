#include "../include/disk_bs_tree.h"

struct tree {
    Disk* disk;
    Tree* left;
    Tree* right;
};

Tree* create_tree(Disk* disk) {
    Tree* tree = (Tree*) malloc(sizeof(Tree));
    tree->disk = disk;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}

int is_empty_tree(Tree* tree) {
    return tree == NULL;
}

int is_leaf_node(Tree* tree) {
    return is_empty_tree(tree->left) && is_empty_tree(tree->right);
}

void free_tree(Tree* tree) {
    if(!is_empty_tree(tree)) {
        free_tree(tree->left);
        free_tree(tree->right);
        free_disk(tree->disk);
        free(tree);
    }
}

void print_tree(Tree* tree) {
    printf("<");
    if(tree != NULL){
        print_disk(tree->disk);
        print_tree(tree->left);
        print_tree(tree->right);
    }
    printf(">");
}

Tree* insert_disk_in_tree(Tree* tree, Disk* disk){
    if(tree != NULL){
        if(get_freeSpace(disk) <= get_freeSpace(tree->disk)){
            tree->left = insert_disk_in_tree(tree->left, disk);
        
        } else if(get_freeSpace(disk) > get_freeSpace(tree->disk)){
            tree->right = insert_disk_in_tree(tree->right, disk);
        }

    } else{ //Arrived in a leaf node
        tree = create_tree(disk);
    }
    return tree;
}

static void swap(Disk** a, Disk** b) {
    Disk* aux = *a;
    *a = *b;
    *b = aux;
}

void search_min_disk_in_tree(Tree* tree, File* file, Disk** min) {
    if(is_empty_tree(tree)) return;

    if(there_is_space(tree->disk, file)) { // Fits in dad, see if fits in left.
        *min = tree->disk;
        search_min_disk_in_tree(tree->left, file, min);
    
    } else { // It doesn't fit in dad, see if fits in right.
        search_min_disk_in_tree(tree->right, file, min);
    }
}

Tree* remove_min_disk_in_tree(Tree* tree, int key, Disk** removed) {
    Tree* aux;
    if(is_empty_tree(tree)) return NULL;

    if(get_freeSpace(tree->disk) == key) { // It has found, remove.
        *removed = tree->disk;

        if(is_leaf_node(tree)){ // Leaf
            free(tree);
            return NULL; // Updating father node 
            
        } else if(tree->left != NULL ^ tree->right != NULL){ // Only one son (^ is xor).
            if(tree->left != NULL){ // Left is only child.
                aux = tree->left;
                
            } else{ // Right is only child.
                aux = tree->right;
            }
            free(tree);
            return aux; // Linking with father node
        
        } else{ // Two children.
            aux = tree->left;
            while(aux->right != NULL){ // Searching successor.
                aux = aux->right;
            }
            swap(&tree->disk, &aux->disk);
            tree->left = remove_min_disk_in_tree(tree->left, key, removed);
        }
    
    } else if(key < get_freeSpace(tree->disk)) { // Searching in left.
        tree->left = remove_min_disk_in_tree(tree->left, key, removed);
    
    } else { // Searching in right.
        tree->right = remove_min_disk_in_tree(tree->right, key, removed);
    }

    return tree;
}
