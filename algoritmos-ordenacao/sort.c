#include "sort.h"

int* create_random_array(int length){
    int* array = (int*) malloc(sizeof(int) * length);

    srand(time(NULL));

    for(int i = 0; i < length; i++){
        array[i] = rand();
    }

    return array;
}

int* create_sorted_array(int length){
    int* array = (int*) malloc(sizeof(int) * length);

    for(int i = 0; i < length; i++){
        array[i] = i;
    }

    return array;
}

int* create_inverted_array(int length){
    int* array = (int*) malloc(sizeof(int) * length);

    for(int i = 0; i < length; i++){
        array[i] = length - i - 1;
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
    int inserted, j, gap;

    for(gap = 1; gap < length; gap = 3 * gap + 1);
    gap = (gap - 1) / 3;

    for(gap; gap > 0; gap = (gap - 1) / 3){

        for(int i = gap; i < length; i++){
            inserted = array[i];

            for(j = i - gap; j >= 0 && inserted < array[j]; j -= gap){
                array[j + gap] = array[j];
            }

            array[j + gap] = inserted;
        }
    }
}

static int is_between(int a, int b, int c){ // is a between b and c?
    return (b <= a && a <= c) || (c <= a && a <= b);
}

static int pivo_position(int* array, int begin, int end){
    int mid = (begin + end) / 2;
    if(is_between(array[begin], array[mid], array[end])) return begin;
    if(is_between(array[mid], array[begin], array[end])) return mid;
    if(is_between(array[end], array[begin], array[mid])) return end;
}

static void partition(int* array, int begin, int end){
    if(begin >= end) return;
    
    int pivo = pivo_position(array, begin, end);
    swap(&array[begin], &array[pivo]);

    pivo = begin;
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

static void max_heapify(int* array, int length, int i){
    if(i >= length) return;
    
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < length && array[left] > array[largest]) largest = left;
    if(right < length && array[right] > array[largest]) largest = right;

    if(largest != i){
        swap(&array[i], &array[largest]);
        max_heapify(array, length, largest);
    }
}

static int dad(int i){
    return (i - 1) / 2;
}

static void create_heap(int* array, int length){
    for(int i = dad(length - 1); i >= 0; i--){
        max_heapify(array, length, i);
    }
}

void heap_sort(int* array, int length){
    create_heap(array, length);

    for(int i = length - 1; i >= 0; i--){
        swap(&array[0], &array[i]);
        max_heapify(array, i, 0);
    }
}

static void merge(int* array, int left, int mid, int right){
    int size_left_half = mid - left + 1;
    int size_right_half = right - mid;

    int* left_half = (int*) malloc(sizeof(int) * size_left_half);
    int* right_half = (int*) malloc(sizeof(int) * size_right_half);

    for(int i = 0; i < size_left_half; i++) 
        left_half[i] = array[left + i];

    for(int j = 0; j < size_right_half; j++) 
        right_half[j] = array[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    
    while(i < size_left_half && j < size_right_half){
        if(left_half[i] < right_half[j]){
            array[k] = left_half[i];
            i++;
        } else{
            array[k] = right_half[j];
            j++;
        }
        k++;
    }
    
    if(i < size_left_half){
        for(i; i < size_left_half; i++, k++) 
            array[k] = left_half[i];   
        
    } else{
        for(j; j < size_right_half; j++, k++) 
            array[k] = right_half[j]; 
    }

    free(left_half);
    free(right_half);
}

static void aux_merge_sort(int* array, int left, int right){
    if(left >= right) return;
    
    int mid = (left + right) / 2;
    
    aux_merge_sort(array, left, mid);
    aux_merge_sort(array, mid + 1, right);
    
    merge(array, left, mid, right);
}

void merge_sort(int* array, int length){
    aux_merge_sort(array, 0, length - 1);
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
