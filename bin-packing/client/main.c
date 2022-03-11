#include <stdio.h>
#include <stdlib.h>
#include "../include/file.h"
#include "../include/file_array.h"
#include "../include/disk.h"
#include "../include/disk_max_heap.h"

int main(int argc, char** argv) {
    if(argc != 2) {
        printf("Incorrect number of parameters.");
        exit(1);
    }

    FileArray* fileArray = reader(argv[1]);

    Heap* heap = create_heap(fileArray);    
    
    Disk* disk0 = create_disk();
    Disk* disk1 = create_disk();
    Disk* disk2 = create_disk();
    Disk* disk3 = create_disk();
    Disk* disk4 = create_disk();

    File* file0 = get_file_at_index(fileArray, 0);
    File* file1 = get_file_at_index(fileArray, 1);
    File* file2 = get_file_at_index(fileArray, 2);
    File* file3 = get_file_at_index(fileArray, 3);
    File* file4 = get_file_at_index(fileArray, 4);

    insert_file_in_disk(disk0, file0);
    insert_file_in_disk(disk1, file1);
    insert_file_in_disk(disk2, file2);
    insert_file_in_disk(disk3, file3);
    insert_file_in_disk(disk4, file4);

    insert_disk_in_heap(heap, disk0);
    insert_disk_in_heap(heap, disk1);
    insert_disk_in_heap(heap, disk2);
    insert_disk_in_heap(heap, disk3);
    insert_disk_in_heap(heap, disk4);

    print_heap(heap);

    Disk* d = remove_max_disk_in_heap(heap);
    Disk* e = remove_max_disk_in_heap(heap);
    printf("After removing:\n");
    print_heap(heap);

    free_disk(d);
    free_disk(e);
    free_heap(heap);
    free_file_array(fileArray);

    return 0;
}
