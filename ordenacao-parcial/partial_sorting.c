#include "partial_sorting.h"

#define TRUE 1
#define FALSE 0

struct array {
    int* v;
    int size;    //max quantity
    int length;  //atual quantity
};

Array* create_array(int size) {
    Array* array = (Array*) malloc(sizeof(Array));
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

int get_element(Array* array, int index){
    return array->v[index];
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
    //srand(time(NULL));
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

Report* partial_selection_sort(Array* array , int k) {
    Report* r = create_report(k, "seleção", array->length);
    if(k > array->length) return NULL;
    
    clock_t start = clock();

    int max;
    
    for(int i = 0; i < k ; i++){
        max = i;
        for(int j = i + 1 ; j < array->size ; j++) {
            if(array->v[j] > array->v[max])
                max = j;   
            increment_comparation(r);
        }
        swap(&array->v[i], &array->v[max]);
        increment_swap(r);
    }

    clock_t end = clock();
   
    double time = ((double) (end - start)) / CLOCKS_PER_SEC;
    set_time(r, time);

    fill_array_topK(r, array, FALSE);

    return r; 
}

Report* partial_insertion_sort(Array* array, int k) {
    if(k > array->length) return NULL;

    Report* r = create_report(k, "inserção", array->length);

    clock_t start = clock();

    int inserted, j;
    for(int i = 1; i < array->size; i++){
        inserted = array->v[i];
        
        if(i > k - 1) {
            increment_comparation(r);
            if(array->v[i] > array->v[k - 1]) {
                swap(&array->v[i], &array->v[k - 1]);
                increment_swap(r);
                j = k - 2;
            
            } else {
                continue;
            }
        } else {
            j = i - 1;
        }
        
        for(j; j >= 0; j--){
            increment_comparation(r);
            if(inserted <= array->v[j])
                break;
            
            increment_swap(r);
            array->v[j + 1] = array->v[j];
        }

        array->v[j + 1] = inserted;
    }

    clock_t end = clock();
   
    double time = ((double) (end - start)) / CLOCKS_PER_SEC;
    set_time(r, time);

    fill_array_topK(r, array, FALSE);
    return r;
}

Report* partial_shell_sort(Array* array, int k) {
    if(k > array->length) return NULL;
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
    return NULL;
}//qtd <= k-1

static void partition(int* array, int begin, int end, int k, Report* report){
    if(begin >= end) return;
    
    int pivo = begin;
    int j = begin + 1;

    for(int i = begin; i <= end; i++){
        if(array[i] > array[pivo]){
            swap(&array[j], &array[i]);
            increment_swap(report);
            j++;
        }
        increment_comparation(report);
    }

    swap(&array[pivo], &array[j - 1]);
    increment_swap(report);
    
    pivo = j - 1;

    partition(array, begin, pivo - 1, k, report);
    if(pivo - begin < k){
        partition(array, pivo + 1, end, k, report);    
    }
}

Report* partial_quick_sort(Array* array, int k) {
    if(k > array->length) return NULL;
    
    Report* r = create_report(k, "quicksort", array->length);
    clock_t start = clock();

    partition(array->v, 0, array->size - 1, k, r);
    
    clock_t end = clock();

    double time = ((double) (end - start)) / CLOCKS_PER_SEC;
    set_time(r, time);
    fill_array_topK(r, array, FALSE);
    return r;
}

static void min_heapify(Array* array, int size, int i, Report* report) {
    // Find largest among root, left child and right child
    int small = i;  //i eh a posiçao do pai
    int left = 2 * i + 1;
    int right = 2 * i + 2;
      
    if(left < size && array->v[left] > array->v[small])
        small = left;
    increment_comparation(report);
    
    if(right < size && array->v[right] > array->v[small])
        small = right;
    increment_comparation(report);    

    increment_comparation(report);
    if(small != i){
        swap(&array->v[i], &array->v[small]);
        increment_swap(report);
        min_heapify(array, size, small, report);
    }
}

Report* partial_heap_sort(Array* array, int k) {   
    if(k > array->length) return NULL;

    Report* r = create_report(k, "heapsort", array->length);
    clock_t start = clock();
    
    for (int i = array->size / 2 - 1; i >= 0; i--) 
        min_heapify(array, array->size, i, r);

    for (int i = array->size - 1;  i >= array->size - k; i--) {
        swap(&array->v[0], &array->v[i]); 
        increment_swap(r); 
        min_heapify(array, i, 0, r);
    } 
    
    clock_t end = clock();

    double time = ((double) (end - start)) / CLOCKS_PER_SEC;
    set_time(r, time);
    fill_array_topK(r, array, TRUE);
    return r;
}

Array* copy_array(Array* array){
    Array* new = create_array(array->size);

    for(int i = 0; i < new->size; i++){
        insert_element_array(new, get_element(array, i));
    }
    return new;
}