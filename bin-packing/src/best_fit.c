#include "../include/best_fit.h"

#define SUCCESS 1
#define FAIL 0

int best_fit(FileArray* fileArray) {
    if(get_length_array(fileArray) == 0) return 0;

    Disk* firstDisk = create_disk();
    insert_file_in_disk(firstDisk, get_file_at_index(fileArray, 0));
    
    // Initializing tree with first disk.
    Tree* tree = create_tree(firstDisk);
    int quantityDisks = 1;

    // For each file in array.
    for(int i = 1; i < get_size_array(fileArray); i++) {
        File* file = get_file_at_index(fileArray, i);
        Disk* min = NULL;
        search_min_disk_in_tree(tree, file, &min); // Look for ideal disk and put it in min.

        if(min == NULL) { // If there isn't ideal disk, create a new one and insert it in tree. 
            Disk* newDisk = create_disk();
            insert_file_in_disk(newDisk, file);
            tree = insert_disk_in_tree(tree, newDisk);
            quantityDisks++;
        
        } else { // If there is, remove disk from tree.
            Disk* removed = NULL;
            tree = remove_min_disk_in_tree(tree, get_freeSpace(min), &removed);
            insert_file_in_disk(removed, file);
            
            if(get_freeSpace(removed) != 0) { // After inserting a file in disk, if still there is space in the disk, insert it again in tree 
            } else { // If there isn't enoght space anymore, it doesn't need to insert the disk in the tree.
                free_disk(removed);
            }
        }
    }

    free_tree(tree);
    return quantityDisks;
}

int best_fit_decreasing(FileArray* fileArray) {
    sort_array(fileArray);
    return best_fit(fileArray);
}
