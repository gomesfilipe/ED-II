#include "sort.h"

int main(){
    int length = 100000;
    int* array = create_array(length);
    //print_array(array, length);

    //bubble_sort(array, length);
    //selection_sort(array, length);
    //insertion_sort(array, length);
    //shell_sort(array, length);

    quick_sort(array, length);
    //print_array(array, length);

    printf("chegou aq\n\n");
    if(is_sorted(array, length)){
        printf("Ordenado!\n");
    }

    free_array(array);
}
