#ifndef SUFFIX_H
#define SUFFIX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str.h"
#include <ctype.h>

typedef struct suffix Suffix;

Suffix* create_suffix(String *s, int index);

void destroy_suffix(Suffix *suf);

void print_suffix(Suffix *suf);

Suffix** create_suf_array(String *text, int N);

void destroy_suf_array(Suffix* *a, int N);

void print_suf_array(Suffix* *a, int N);

// Use uma (ou mais) funcoes deste tipo para ordenar
// o arry de sufixos usando o qsort e outro metodo de sua escolha
void sort_suf_array(Suffix* *a, int N);

void heap_sort_suf_array(Suffix* *a, int N);

int rank(Suffix* *a, int N, String *query);

int binary_search(Suffix** a, int N, String* query);

void print_binary_search(Suffix** a, int N, int first, int context, String* query);

int search_first_query(Suffix** a, int N, String* query);

#endif
