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
    if(k > array->length) return;
    
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
    if(k > array->length) return;
    
    int inserted, j;
    for(int i = 1; i < array->size; i++){
        inserted = array->v[i];
        
        if(i > k - 1) {
            if(array->v[i] < array->v[k - 1]) {
                swap(&array->v[i], &array->v[k - 1]);
                j = k - 2;
            
            } else {
                continue;
            }
        } else {
            j = i - 1;
        }
        
        for(j; j >= 0; j--){
            if(inserted >= array->v[j])
                break;
            
            array->v[j + 1] = array->v[j];
        }

        array->v[j + 1] = inserted;
    }
}

void partial_shell_sort(Array* array, int k) {
    if(k > array->length) return;
    //int qtd=0;
    int gap;
    for(gap = 1; gap < array->size; gap = 3 * gap + 1); //Calculando gap
    gap = (gap - 1) / 3; //ajustando gap

    int inserted, j;
    for(gap; gap > 0; gap = (gap - 1) / 3){
        for(int i = gap; i < array->size; i++){
            //if(qtd >= k-1) break;
            
            inserted = array->v[i];  

            for(j = i - gap; j >= 0 ; j -= gap){
                if(inserted >= array->v[j])
                    break;
                
                array->v[j + gap] = array->v[j];
                //qtd++;
            }

            array->v[j + gap] = inserted;
        }
    }
}//qtd <= k-1

static void partition(int* array, int begin, int end, int k){
    if(begin >= end) return;
    
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

    partition(array, begin, pivo - 1, k);
    if(pivo - begin < k){
        partition(array, pivo + 1, end, k);    
    }
}

void partial_quick_sort(Array* array, int k) {
    if(k > array->length) return;
}

void partial_heap_sort(Array* array, int k) {
    if(k > array->length) return;
}
