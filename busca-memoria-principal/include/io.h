#ifndef IO_H
#define IO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str.h"

/**
* @brief Essa função realiza a leitura do arquivo de entrada.
* @param fileName É o ponteiro do arquivo de entrada.
* @return Retorna uma String contendo todos os caracteres contidos no arquivo de entrada.
*/
String* read_txt(char* fileName);

/**
* @brief 
* @param argv
* @param control_keys
* @param fileName
* @param context
* @param query
* @return 
*/
void split(char** argv, int* control_keys, char* fileName, int* context, char* query);

#endif
