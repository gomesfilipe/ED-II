#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/partial_sorting.h"
#include "../include/report.h"
#include "../include/io.h"

#define TAM 123 // Para alcançar o z na tabela de dispersão
#define FALSE 0

int main(int argc, char** argv){
    if(argc != 4){
        printf("Incorrect number of parameters!\n");
        return 1;
    }

    int control_keys[TAM] = {FALSE};
    int k;
    char fileName[100];
    split(argv, control_keys, &k, fileName);  

    Array* array = read_file(fileName);

    build_report(array, k, control_keys, fileName);

    free_array(array);

    // char alg, report;
    // int k;
    // char fileName[100];
    // split(argv, &alg, &report, &k, fileName);  

    // Array* array = read_file(fileName);

    // build_report(array, k, report, alg, fileName);

    // free_array(array);


    return 0;
}

/* TODO
    Fazer relatorio
    Fazer a shell sort
    Resolver segmentation fault: quick sort, pasta quase-ordenado
*/
