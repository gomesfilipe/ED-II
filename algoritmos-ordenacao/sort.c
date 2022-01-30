#include "sort.h"

int* create_array(int length){
    int* array = (int*) malloc(sizeof(int) * length);

    srand(time(NULL));

    for(int i = 0; i < length; i++){
        array[i] = rand();
    }

    return array;
}

void free_array(int* array){
    free(array);
}

void print_array(int* array, int length){
    for(int i = 0; i < length; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

void swap(int* a, int* b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void bubble_sort(int* array, int length){
    for(int i = 0; i < length; i++){
        for(int j = 0; j < length - 1; j++){
            if(array[j] > array[j + 1]){
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

void selection_sort(int* array, int length){
    int smaller_position;

    for(int i = 0; i < length; i++){
        smaller_position = i;

        for(int j = i + 1; j < length; j++){
            if(array[j] < array[smaller_position]){
                smaller_position = j;
            }
        }

        swap(&array[i], &array[smaller_position]);
    }
}

void insertion_sort(int* array, int length){
    int inserted, j;
    for(int i = 1; i < length; i++){
        inserted = array[i];
        
        for(j = i - 1; j >= 0 && inserted < array[j]; j--){
            array[j + 1] = array[j];
        }

        array[j + 1] = inserted;
    }
}

void shell_sort(int* array, int length){
    int inserted, j;
    for(int gap = length / 2; gap > 0; gap /= 2){

        for(int i = gap; i < length; i += gap){
            inserted = array[i];

            for(j = i - gap; j >= 0 && inserted < array[j]; j -= gap){
                array[j + gap] = array[j];
            }

            array[j + gap] = inserted;
        }
    }
}

void partition(int * array, int begin, int end){
    if(begin >= end ) return;
    
    int pivo = begin;
    int j = begin + 1;

    for(int i = begin; i <= end; i++){
        if(array[i] < array[pivo]){
            swap(&array[j], &array[i]);
            j++;
        }
    }

    swap(&array[pivo], &array[j - 1]);
    
    pivo = j - 1;

    partition(array, begin, pivo - 1);
    partition(array, pivo + 1, end);
}

void quick_sort(int* array, int length){
    partition(array, 0, length - 1);
}

int is_sorted(int* array, int length){
    for(int i = 0; i < length - 1; i++){
        if(array[i] > array[i + 1]){
            return 0;
        }
    }
    return 1;
}

double timer(fptr sort_function, int* array, int length){
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    sort_function(array, length);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}
