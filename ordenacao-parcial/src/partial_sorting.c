#include "../include/partial_sorting.h"

#define TRUE 1
#define FALSE 0

struct array {
    int* v;
    int size;    // Total de elementos que o vetor suporta.
    int length;  // Quantidade de elementos presente no vetor.
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

Report* partial_selection_sort(Array* array , int k) {
    if(k > array->length) return NULL;
    
    Report* r = create_report(k, "seleção", array->length);

    clock_t start = clock();

    int max;
    
    for(int i = 0; i < k ; i++){
        max = i;
        for(int j = i + 1 ; j < array->size ; j++) { // Pega o maior elemento.
            if(array->v[j] > array->v[max])
                max = j;   
            increment_comparation(r);
        }
        swap(&array->v[i], &array->v[max]); // Coloca o maior no início.
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
        
        // Verifica se está na k-ésima posição ou não, para definir onde começar o próximo laço.
        if(i > k - 1) { 
            increment_comparation(r);
            if(array->v[i] > array->v[k - 1]) { // Se for maior que o k-ésimo elemento, faz o swap e ajusta o j para ordenar parcialmente.
                swap(&array->v[i], &array->v[k - 1]);
                increment_swap(r);
                j = k - 2;
            
            } else { // Se não for maior, ignora e passa para o próximo loop.
                continue;
            }
        } else { // Antes do k-ésimo, ajusta j para fazer a lógica normal do insertion sort.
            j = i - 1;
        }
        
        for(j; j >= 0; j--){
            increment_comparation(r);
            if(inserted <= array->v[j])
                break;
            
            increment_swap(r);
            array->v[j + 1] = array->v[j]; 
        }

        array->v[j + 1] = inserted; // Inserindo elemento em sua posição correta.
    }

    clock_t end = clock();
   
    double time = ((double) (end - start)) / CLOCKS_PER_SEC;
    set_time(r, time);

    fill_array_topK(r, array, FALSE);
    return r;
}

Report* partial_shell_sort(Array* array, int k) {
    if(k > array->length) return NULL;

    Report* r = create_report(k, "shellsort", array->size);

    clock_t start = clock();

    int gap;
    for(gap = 1; gap < array->size; gap = 3 * gap + 1); // Calculando gap.
    gap = (gap - 1) / 3; // Ajustando para ser menor que o tamanho do vetor.

    int inserted, j;
    for(gap; gap > 0; gap = (gap - 1) / 3){
        for(int i = gap; i < array->size; i++){    
            inserted = array->v[i];  
            
            unsigned long long kesimo = (i % gap) + (k - 1) * gap; // índice do k-ésimo elemento no subvetor
            if(i > kesimo){ // Verifica se está na k-ésima posição ou não do subvetor, para definir onde começar o próximo laço. 
                increment_comparation(r);
                if(array->v[i] > array->v[kesimo]){ // Se for maior que o k-ésimo elemento do subvetor, faz o swap e ajusta o j para ordená-lo parcialmente.
                    swap(&array->v[i], &array->v[kesimo]);
                    increment_swap(r);
                    j = kesimo - gap;
                
                } else{ // Se não for maior, ignora e passa para o próximo loop.
                    continue;
                }
            } else {
                j = i - gap;
            }

            for(j; j >= 0 ; j -= gap){
                increment_comparation(r);
                if(inserted <= array->v[j])
                    break;
                
                increment_swap(r);
                array->v[j + gap] = array->v[j];
            }

            array->v[j + gap] = inserted; // Inserindo elemento em sua posição correta.
        }
    }

    clock_t end = clock();

    double time = ((double) (end - start)) / CLOCKS_PER_SEC;
    set_time(r, time);

    fill_array_topK(r, array, FALSE);
    return r;
}

static void partition(Array* array, int begin, int end, int k, Report* report){
    if(begin >= end) return;
    
    int pivo = begin; // Elemento pivô é o mais a esquerda.
    int j = begin + 1; // Controla onde serão colocados os elementos maiores que o pivô.

    for(int i = begin; i <= end; i++){ // Percorre toda a partição.
        if(array->v[i] > array->v[pivo]){ // Se for maior que o pivô, faz o swap.
            swap(&array->v[j], &array->v[i]);
            increment_swap(report);
            j++;
        }
        increment_comparation(report);
    }

    swap(&array->v[pivo], &array->v[j - 1]); // Colocando o pivô em sua posição correta. 
    increment_swap(report);
    
    pivo = j - 1;

    partition(array, begin, pivo - 1, k, report);
    if(pivo - begin < k){ // Só chama a partição a direita se a partição a esquerda tiver tamanho menor que k.
        partition(array, pivo + 1, end, k, report);    
    }
}

Report* partial_quick_sort(Array* array, int k) {
    if(k > array->length) return NULL;
    
    Report* r = create_report(k, "quicksort", array->length);
    clock_t start = clock();

    partition(array, 0, array->size - 1, k, r);
    
    clock_t end = clock();

    double time = ((double) (end - start)) / CLOCKS_PER_SEC;
    set_time(r, time);
    fill_array_topK(r, array, FALSE);
    return r;
}

static void max_heapify(Array* array, int size, int i, Report* report) {
    // Definindo os índices do elemento pai e seus filhos.
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Os próximos 2 ifs descobrem o índice do maior elemento dentre o pai e os filhos. 
    if(left < size && array->v[left] > array->v[largest])
        largest = left;
    increment_comparation(report);
    
    if(right < size && array->v[right] > array->v[largest])
        largest = right;
    increment_comparation(report);    

    increment_comparation(report);

    if(largest != i){ // Se o índice do maior elemento não for o do pai, faz o swap e chama a função recursivamente.
        swap(&array->v[i], &array->v[largest]);
        increment_swap(report);
        max_heapify(array, size, largest, report);
    }
}

Report* partial_heap_sort(Array* array, int k) {   
    if(k > array->length) return NULL;

    Report* r = create_report(k, "heapsort", array->length);
    clock_t start = clock();
    
    // Constrói o heap. 
    for (int i = array->size / 2 - 1; i >= 0; i--) 
        max_heapify(array, array->size, i, r);

    // Pega o maior elemento do heap, coloca no final do vetor e reconstrói o heap para os elementos restantes.
    for (int i = array->size - 1;  i >= array->size - k; i--) {
        swap(&array->v[0], &array->v[i]); 
        increment_swap(r); 
        max_heapify(array, i, 0, r);
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
