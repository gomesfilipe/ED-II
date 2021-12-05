#include "sort.h"

#define QTDALGORITMOS 5

int main(){
    fptr sort_functions[QTDALGORITMOS] = {
        bubble_sort,
        selection_sort, 
        insertion_sort, 
        shell_sort, 
        quick_sort
    };

    char* sort_names[QTDALGORITMOS] = {
        "Bubble Sort", 
        "Selection Sort", 
        "Insertion Sort", 
        "Shell Sort", 
        "Quick Sort"
    };

    FILE *f = fopen("analise2.txt", "w");
    
    if(f == NULL){
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }

    int x = 0;

    for(int length = 5000; length <= 1280000; length *= 2){
        fprintf(f, "Tamanho do vetor: %d\n", length);

        for(int i = 0; i < QTDALGORITMOS; i++){
            int* array = create_array(length);

            double time = timer(sort_functions[i], array, length);

            fprintf(f, "%s: %.3lf s\n", sort_names[i], time);

            free_array(array);

            printf("[%d]\n", x++); // Para me situar em qual ponto da execução está.
        }

        fprintf(f, "\n");
    }

    fclose(f);
    return 0;
}
