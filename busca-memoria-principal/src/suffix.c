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
    destroy_string(suf->s);
    free(suf);
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
        destroy_suffix(a->[i]);
    }
    free(a);
}

void print_suf_array(Suffix* *a, int N){
    for (int i = 0; i < N ; i++){
        print_suffix(a->[i]);
    }
}

static int compare_suf(Suffix* a, Suffix* b){
    String* A = a->s + a->index;
    String* B = b->s + b->index;
    return compare(A, B);
}

void sort_suf_array(Suffix* *a, int N){
    qsort(a, N, sizeof(Suffix*), compare_suf);
}

int rank(Suffix* *a, int N, String *query){

}
