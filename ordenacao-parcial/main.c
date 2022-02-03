#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "partial_sorting.h"
#include "report.h"
#include "io.h"
#include <string.h>

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

    return 0;
}

/*
    Consertar tempo de CPU, so esta pegando 00000
    Testar mais casos
    Fazer a shell sort
    Fazer relatorio

*/
