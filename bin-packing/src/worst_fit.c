#include "../include/worst_fit.h"

#define SUCCESS 1
#define FAIL 0

int worst_fit(FileArray* fileArray) {
    if(get_length_array(fileArray) == 0) return 0;
    
    Heap* heap = create_heap(fileArray);
    
    Disk* firstDisk = create_disk();
    insert_file_in_disk(firstDisk, get_file_at_index(fileArray, 0));
    insert_disk_in_heap(heap, firstDisk);

    for(int i = 1; i < get_size_array(fileArray); i++) {
        Disk* disk = get_first_disk_in_heap(heap);
        File* file = get_file_at_index(fileArray, i);

        if(insert_file_in_disk(disk, file) == SUCCESS) {
            Disk* removed = remove_max_disk_in_heap(heap);
            insert_disk_in_heap(heap, removed);
        
        } else {
            Disk* newDisk = create_disk();
            insert_file_in_disk(newDisk, file);
            insert_disk_in_heap(heap, newDisk);
        }
    }

    int quantityDisks = get_length_heap(heap);
    free_heap(heap);
    return quantityDisks;
}

int worst_fit_descending(FileArray* fileArray) {
    sort_array(fileArray);
    return worst_fit(fileArray);
}
