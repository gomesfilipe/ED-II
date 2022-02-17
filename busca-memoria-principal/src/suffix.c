#include "../include/suffix.h"

struct suffix {
    String* s;
    int index;
};

Suffix* create_suffix(String *s, int index){
    Suffix* suffix = (Suffix*) malloc(sizeof(Suffix));
    char* tam = get_c(s);
    suffix->s = create_string(get_c(s) + index);
    suffix->index = index;
    return suffix;
}

void destroy_suffix(Suffix *suf){
    destroy_string(suf->s);
    free(suf); 
}

void print_suffix(Suffix *suf){
    print_substring(suf->s, 0, get_len(suf->s));
    //printf("  index [%d]", suf->index);
}

Suffix** create_suf_array(String *text, int N){
    Suffix** suf_array = (Suffix**) malloc(sizeof(Suffix*) * N);

    for(int i = 0; i < N; i++){
        suf_array[i] = create_suffix(text, i);
    }

    return suf_array;
}

void destroy_suf_array(Suffix* *a, int N){
    for (int i = 0; i < N ; i++){
        destroy_suffix(a[i]);
    }
    free(a);
}

void print_suf_array(Suffix** a, int N){
    for (int i = 0; i < N ; i++){
        print_suffix(a[i]);
        printf("\n");
    }
}

static int compare_suf(const void* a, const void* b){
    Suffix* sufA = *(Suffix**) a;
    Suffix* sufB = *(Suffix**) b;
    return compare(sufA->s, sufB->s);
}

void sort_suf_array(Suffix** a, int N){    
    qsort(a, N, sizeof(Suffix*), compare_suf);
}


static void swap(Suffix** a, Suffix** b){
    Suffix* aux = *a;
    *a = *b;
    *b = aux;
}

static void max_heapify(Suffix** array, int size, int i) {
    // Definindo os índices do elemento pai e seus filhos.
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Os próximos 2 ifs descobrem o índice do maior elemento dentre o pai e os filhos. 
    // if(left < size && array->v[left] < array->v[largest])
    //     largest = left;
    
    if(left < size && compare_suf(&array[left], &array[largest]) == 1)
        largest = left;
    
    // if(right < size && array->v[right] < array->v[largest])
    //     largest = right;

    if(right < size && compare_suf(&array[right], &array[largest]) == 1)
        largest = right; 

    if(largest != i){ // Se o índice do maior elemento não for o do pai, faz o swap e chama a função recursivamente.
        swap(&array[i], &array[largest]);
        max_heapify(array, size, largest);
    }
}

void heap_sort_suf_array(Suffix** array, int N){
    // Constrói o heap. 
    for (int i = N / 2 - 1; i >= 0; i--) 
        max_heapify(array, N, i);

    // Pega o maior elemento do heap, coloca no final do vetor e reconstrói o heap para os elementos restantes.
    for (int i = N - 1;  i >= 0; i--) {
        swap(&array[0], &array[i]); 
        max_heapify(array, i, 0);
    } 
}

// Report* partial_heap_sort(Array* array, int k) {   
//     if(k > array->length) return NULL;

//     Report* r = create_report(k, "heapsort", array->length);
//     clock_t start = clock();
    
//     // Constrói o heap. 
//     for (int i = array->size / 2 - 1; i >= 0; i--) 
//         max_heapify(array, array->size, i, r);

//     // Pega o maior elemento do heap, coloca no final do vetor e reconstrói o heap para os elementos restantes.
//     for (int i = array->size - 1;  i >= array->size - k; i--) {
//         swap(&array->v[0], &array->v[i]); 
//         increment_swap(r); 
//         max_heapify(array, i, 0, r);
//     } 
    
//     clock_t end = clock();

//     double time = ((double) (end - start)) / CLOCKS_PER_SEC;
//     set_time(r, time);
//     fill_array_topK(r, array, TRUE);
//     return r;
// }


int rank(Suffix* *a, int N, String *query){

}
