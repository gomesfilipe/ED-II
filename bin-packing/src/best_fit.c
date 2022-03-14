#include "../include/best_fit.h"

#define SUCCESS 1
#define FAIL 0

int best_fit(FileArray* fileArray) {
    if(get_length_array(fileArray) == 0) return 0;

    Disk* firstDisk = create_disk();
    insert_file_in_disk(firstDisk, get_file_at_index(fileArray, 0));
    
    Tree* tree = create_tree(firstDisk);
    // print_tree(tree);
    // printf("\n\n");
    int quantityDisks = 1;

    for(int i = 1; i < get_size_array(fileArray); i++) {
        // printf("----------\n");
        File* file = get_file_at_index(fileArray, i);
        // printf("laço [%d]\n\n", i);
        // printf("file size %d\n", get_size(file));
        
        Disk* min = NULL;
        search_min_disk_in_tree(tree, file, &min);
        
        // if(min != NULL){
        //     // printf("min disk: ");
        //     print_disk(min);
        // } else {
        //     printf("nao ha min disk\n");
        // }

        // print_tree(tree);

        if(min == NULL) {
            // printf("\nnao removeu\n");
            Disk* newDisk = create_disk();
            insert_file_in_disk(newDisk, file);
            tree = insert_disk_in_tree(tree, newDisk);
            // printf("arvore dps de inserir:\n");
            // print_tree(tree);
            quantityDisks++;
        
        } else {
            Disk* removed = NULL;
            tree = remove_min_disk_in_tree(tree, get_freeSpace(min), &removed);

            // printf("arvore apos remover:\n\n");
            // print_tree(tree);
        //     // printf("[%d]", removed == NULL);
        //     // printf("\nremoveu: ");
        //     // print_disk(removed);
            insert_file_in_disk(removed, file);
            
            
        //     printf("depois de inserir arquivo no disco: ");
            // print_disk(removed);
            if(get_freeSpace(removed) != 0) {
                tree = insert_disk_in_tree(tree, removed);
            } else {
                free_disk(removed);
            }
        //     printf("\narvore dps de reinserir:\n");
        //     print_tree(tree);
        //     printf("\n");
        }

        // printf("----------\n");
    }

    // print_tree(tree);

    free_tree(tree);
    return quantityDisks;
}

int best_fit_descending(FileArray* fileArray) {
    sort_array(fileArray);
    return best_fit(fileArray);
}
