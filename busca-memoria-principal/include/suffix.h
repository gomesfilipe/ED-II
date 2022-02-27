#ifndef SUFFIX_H
#define SUFFIX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str.h"
#include <ctype.h>

typedef struct suffix Suffix;

/**
 * @brief Construtor de um sufixo.
 * @param s String a qual o sufixo está contida.
 * @param index Índice de início do sufixo na string.
 * @return Sufixo inicializado.
 */
Suffix* create_suffix(String *s, int index);

/**
 * @brief Libera um sufixo da memória. Não libera o campo do tipo String*, 
 * pois neste trabalho todos os sufixos possuem referência para a mesma String.
 * @param suf Sufixo que será liberado.
 */
void destroy_suffix(Suffix *suf);

/**
 * @brief Imprime um sufixo em stdout.
 * @param suf Sufixo que será impresso.
 */
void print_suffix(Suffix *suf);

/**
 * @brief Essa função cria um array de sufixos.
 * @param text É a string que contém o texto que será subdividido em vários sufixos.
 * @param N É o tamanho do array de sufixos que será criado que é o mesmo valor da quantidade de 
 * caracteres da string text.
 */
Suffix** create_suf_array(String *text, int N);

/**
 * @brief Libera um vetor de sufixos da memória.
 * @param a Vetor de sufixos que será liberado.
 * @param N Tamanho do vetor.
 */
void destroy_suf_array(Suffix* *a, int N);

/**
 * @brief Imprime um vetor de sufixos em stdout.
 * @param a Vetor de sufixos que será impresso.
 * @param N Tamanho do vetor.
 */
void print_suf_array(Suffix* *a, int N);

/**
 * @brief Ordena o vetor de sufixos com o algoritmo quicksort.
 * @param a Vetor de sufixos que será ordenado.
 * @param N Tamanho do vetor.
 */
void sort_suf_array(Suffix* *a, int N);

/**
 * @brief Ordena o vetor de sufixos com o algoritmo heapsort.
 * @param a Vetor de sufixos que será ordenado.
 * @param N Tamanho do vetor.
 */
void heap_sort_suf_array(Suffix* *a, int N);

/**
 * @brief Faz uma busca binária num vetor de sufixos ordenado de modo crescente.
 * @param a Vetor de sufixos que será realizada a busca.
 * @param N Tamanho do vetor.
 * @param query Chave da busca.
 * @return Índice do primeiro elemento encontrado que corresponde a chave.
 */
int binary_search(Suffix** a, int N, String* query);

/**
 * @brief Encontra a primeira ocorrência de um elemento de uma determinada chave.
 * É feita uma busca binária até encontrar algum elemento que corresponsa a chave.
 * Após isso, o vetor é percorrido para trás até encontrar a primeira ocorrência.
 * @param a Vetor de sufixos que será realizada a busca.
 * @param N Tamanho do vetor.
 * @param query Chave da busca.
 * @return Índice da primeira ocorrência do elemento encontrado que corresponde a chave.
 */
int rank(Suffix** a, int N, String* query);

/**
 * @brief Imprime as string do arquivo de entrada que contém a string a query, até uma quantidade
 * caracteres context a direita e a esquerda.
 * @param a Vetor de sufixos que será realizada a busca.
 * @param N Tamanho do vetor.
 * @param first Índice da primeira posição no vetor de sufixos que contém a query.
 * @param context Quantidade de caracteres a esquerda e a direita da query que também deverão ser impressos.
 * @param query Chave da busca.
 */
void print_binary_search(Suffix** a, int N, int first, int context, String* query);

#endif
