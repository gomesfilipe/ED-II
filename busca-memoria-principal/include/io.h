#ifndef IO_H
#define IO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "str.h"
#include "suffix.h"

/**
* @brief Essa função realiza a leitura do arquivo de entrada.
* @param fileName É o ponteiro do arquivo de entrada.
* @return Retorna uma String contendo todos os caracteres contidos no arquivo de entrada.
*/
String* read_txt(char* fileName);

/**
 * @brief Executa o programa exigido na especificação conforme argumentos da linha de comando.
 * @param argc Quantidade de argumentos da linha de comando.
 * @param argv Vetor de strings da linha de comando.
 */
void main_memory_search(int argc, char** argv);

#endif
