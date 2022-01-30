#include "partial_sorting.h"

struct array {
    int* v;
    int size;    //max quantity
    int length;  //atual quantity
};

Array* create_array(int size) {
    Array* array = (Array*) malloc(sizeof(Array));
    // array->v = (int*) calloc (size, sizeof(int));
    array->v = (int*) malloc (sizeof(int) * size);
    array->size = size;
    array->length = 0;
    return array;
}

void free_array(Array* array) {
    free(array->v);
    free(array);
}

void print_array(Array* array) {
    for(int i = 0; i < array->size; i++) {
        printf("%02d ", array->v[i]);
    }
    printf("\n\n");
}

int* get_array(Array* array) {
    return array->v;
}

int get_size(Array* array) {
    return array->size;
}

int get_length(Array* array) {
    return array->length;
}

int is_full(Array* array) {
    return array->length == array->size;
}

void insert_element_array(Array* array, int element) {
    if(is_full(array)) {
        return;
    }
    array->v[array->length] = element;
    array->length++;
}

void fill_array(Array* array) {
    srand(time(NULL));

    for(int i = 0; i < array->size; i++) {
        insert_element_array(array, rand() % 100);
    }
}

void swap(int* a, int* b) {
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void partial_selection_sort(Array* array , int k) {
    if(k > array->size) return;
    
    int min = 0;
    // int trocas = 0;
    for(int i = 0; i < k ; i++){
        min = i;
        for(int j = i + 1 ; j < array->size ; j++) {
            if(array->v[j] < array->v[min]) 
                min = j;   
        }
        swap(&array->v[i], &array->v[min]);
        // trocas++;
    }
    // printf("%d trocas\n", trocas);   
}

void partial_insertion_sort(Array* array, int k) {
    if(k > array->size) return;
    
    int inserted, j;
    for(int i = 1; i < array->size; i++){
        inserted = array->v[i];
        
        if(i > k - 1) {
            if(array->v[i] < array->v[k - 1]) {
                swap(&array->v[i], &array->v[k - 1]);
                j = k - 1;
            
            } else {
                continue;
            }
        
        } else {
            j = i - 1;
        }
        
        for(j; j >= 0 && inserted < array->v[j]; j--){
            array->v[j + 1] = array->v[j];
        }

        array->v[j + 1] = inserted;
    }
}

void partial_shell_sort(Array* array, int k) {
    if(k > array->size) return;
}

void partial_quick_sort(Array* array, int k) {
    if(k > array->size) return;
}

void partial_heap_sort(Array* array, int k) {
    if(k > array->size) return;
}
