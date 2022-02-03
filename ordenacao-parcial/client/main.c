#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/partial_sorting.h"
#include "../include/report.h"
#include "../include/io.h"

int main(int argc, char** argv){
    if(argc != 4){
        printf("Incorrect number of parameters!\n");
        return 1;
    }

    char alg, report;
    int k;
    char fileName[100];
    split(argv, &alg, &report, &k, fileName);  

    Array* array = read_file(fileName);

    build_report(array, k, report, alg, fileName);

    free_array(array);
    return 0;
}

/*
    Consertar tempo de CPU, so esta pegando 00000
    Fazer a shell sort
    Fazer relatorio
    Documentar tudo do 0
*/
