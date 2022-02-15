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
    //print_substring(suf->index, suf->index, suf->s->len);
}

Suffix** create_suf_array(String *text, int N){

}

void destroy_suf_array(Suffix* *a, int N){

}

void print_suf_array(Suffix* *a, int N){

}

// Use uma (ou mais) funcoes deste tipo para ordenar
// o arry de sufixos usando o qsort e outro metodo de sua escolha
void sort_suf_array(Suffix* *a, int N){

}

int rank(Suffix* *a, int N, String *query){

}