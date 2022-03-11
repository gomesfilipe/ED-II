#include <stdio.h>
#include <stdlib.h>
#include "../include/file.h"
#include "../include/disk.h"
#include "../include/file_array.h"

int main(int argc, char** argv) {
    if(argc != 2) {
        printf("Incorrect number of parameters.");
        exit(1);
    }

    FileArray* fileArray = reader(argv[1]);

    print_file_array(fileArray);

    sort_array(fileArray);

    printf("After sorting:\n\n");

    print_file_array(fileArray);

    free_file_array(fileArray);

    return 0;
}
