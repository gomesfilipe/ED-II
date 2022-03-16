#include <stdio.h>
#include <stdlib.h>
#include "../include/file.h"
#include "../include/file_array.h"
#include "../include/disk.h"
#include "../include/disk_max_heap.h"
#include "../include/disk_bs_tree.h"
#include "../include/worst_fit.h"
#include "../include/best_fit.h"
#include <time.h>

int main(int argc, char** argv) {
    if(argc != 2) {
        printf("Incorrect number of parameters.");
        exit(1);
    }

    FileArray* fileArray = reader(argv[1]);

    printf("%d\n", worst_fit(fileArray));
    printf("%d\n", best_fit(fileArray));
    printf("%d\n", worst_fit_decreasing(fileArray));
    printf("%d\n", best_fit_decreasing(fileArray)); 
    
    free_file_array(fileArray);
    return 0;
}
