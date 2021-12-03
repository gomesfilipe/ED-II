#include "sort.h"

int main(){
    int length = 10;
    int* array = create_array(length);
    print_array(array, length);

    // bubble_sort(array, length);
    // selection_sort(array, length);
    insertion_sort(array, length);
    print_array(array, length);

    free_array(array);
}
