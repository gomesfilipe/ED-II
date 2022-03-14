#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include <time.h>


int main() {
    FILE *f = fopen("heights.txt", "a");
    
    if(f == NULL) {
        printf("Error.\n");
        exit(1);
    }

    srand(time(NULL));
    
    BST* bst = create_empty_BST();

    for(int i = 0; i < 1000000; i++) {
        bst = insert_BST(bst, rand());
    }

    // for(int i = 0; i < 1000000; i++) {
    //     bst = insert_in_root_BST(bst, rand());
    // }

    fprintf(f, "%d\n", height_BST(bst));

    free_BST(bst);
    fclose(f);
    return 0;
}
