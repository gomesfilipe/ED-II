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

    clock_t start = clock();

    printf("worst fit            [%d] \n", worst_fit(fileArray));
    printf("best fit             [%d]\n", best_fit(fileArray));
    printf("worst fit descending [%d]\n", worst_fit_descending(fileArray));
    printf("best fit descending  [%d]\n\n", best_fit_descending(fileArray));  
    
    clock_t end = clock();
    double time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("execution time [%.3f]\n", time);

    free_file_array(fileArray);
    return 0;
}
