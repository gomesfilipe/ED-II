#include "../include/suffix.h"

struct suffix {
    String* s;
    int index;
};

Suffix* create_suffix(String *s, int index){
    Suffix* suffix = (Suffix*) malloc(sizeof(Suffix));
    suffix->s = s;
    suffix->index = index;
    return suffix;
}

void destroy_suffix(Suffix *suf){
    free(suf); // Não libera a string pois todos os sufixos terão a mesma referência de string.
}

void print_suffix(Suffix *suf){
    print_substring(suf->s, suf->index, get_len(suf->s));
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

static int len_suf(Suffix* suf){
    return get_len(suf->s) - suf->index;
}

static int compare_suf(const void* a, const void* b){
    Suffix* sufA = *(Suffix**) a;
    Suffix* sufB = *(Suffix**) b;
    
    int lenA = len_suf(sufA);
    int lenB = len_suf(sufB);

    char* A = get_c(sufA->s) + sufA->index; // Ajustando ponteiro para o início do sufixo A.
    char* B = get_c(sufB->s) + sufB->index; // Ajustando ponteiro para o início do sufixo B.

    int min = lenA < lenB ? lenA : lenB;
    for(int i = 0; i < min; i++){
        if(tolower(A[i]) < tolower(B[i])) return -1; // tolower() faz que letras maiúsculas e minúsculas sejam tratadas igualmente.
        if(tolower(A[i]) > tolower(B[i])) return 1;
    }  
    return lenA - lenB; 
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
    if(left < size && compare_suf(&array[left], &array[largest]) > 0)
        largest = left;

    if(right < size && compare_suf(&array[right], &array[largest]) > 0)
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

static int partition(Suffix** a, Suffix* query, int begin, int end){
    if(begin > end) return -1;
    
    int pivo = (begin + end) / 2;

    String* string = a[pivo]->s;
    
    if(equals_substring(string, a[pivo]->index, get_len(string), query->s)){ // Encontrou, retornar o index do elemento.
        return pivo;
    
    } else{
        if(compare_suf(&query, &a[pivo]) < 0){ // Query é alfabeticamente menor? Buscar query na partição esquerda.
            return partition(a, query, begin, pivo - 1);
        
        } else if (compare_suf(&query, &a[pivo]) > 0){ // Query é alfabeticamente maior? Buscar query na partição esquerda.
            return partition(a, query, pivo + 1, end);
        }
    }
}

int binary_search(Suffix** a, int N, String* query){
    Suffix* suf_query = create_suffix(query, 0); // Criamos um sufixo a partir da String para facilitar a comparação entre query e os sufixos na busca.
    int position = partition(a, suf_query, 0, N - 1);
    destroy_suffix(suf_query);
    return position;
}

int rank(Suffix** a, int N, String* query){
    int position = binary_search(a, N, query);
    int i;
    
    for(i = position - 1; i >= 0; i--){
        String* s = a[i]->s;
        if(!equals_substring(s, a[i]->index , get_len(s) , query)) break; // Encontrou a primeira posição diferente, encerrar o laço.
    }

    i++; // Corrigindo posição.
    return i; 
}

void print_binary_search(Suffix** a, int N, int first, int context, String* query){
    for(int i = first; i < N && i >= 0; i++){
        String* s = a[i]->s;
        int len = get_len(s); 
        int from = a[i]->index - context;
        int to = a[i]->index + get_len(query) + context;

        if(from < 0) from = 0; // Ajustando extremos do intervalo para não ultrapassar os limites da string.
        if(to > len) to = len;
       
        if(!equals_substring(s, a[i]->index , len , query)) break; // Encontrou elemento diferente de query, encerrar laço.

        print_substring(s, from, to);
        printf("\n");
    }
}
