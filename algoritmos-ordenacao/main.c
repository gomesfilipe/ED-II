#include "sort.h"
#include <string.h>

#define QTDALGORITMOS 4
// #define QTDALGORITMOS 7

int power(int base, int exponent);

int main(){
    // fptr sort_functions[QTDALGORITMOS] = {
    //     bubble_sort,
    //     selection_sort, 
    //     insertion_sort, 
    //     shell_sort, 
    //     quick_sort,
    //     heap_sort, 
    //     merge_sort
    // };

    // char* sort_names[QTDALGORITMOS] = {
    //     "Bubble Sort", 
    //     "Selection Sort", 
    //     "Insertion Sort", 
    //     "Shell Sort", 
    //     "Quick Sort", 
    //     "Heap Sort", 
    //     "Merge Sort"
    // };

    fptr sort_functions[QTDALGORITMOS] = {
        shell_sort, 
        quick_sort,
        heap_sort, 
        merge_sort
    };

    char* sort_names[QTDALGORITMOS] = {
        "Shell Sort", 
        "Quick Sort", 
        "Heap Sort", 
        "Merge Sort"
    };

    FILE *f = fopen("analise-2.txt", "w");
    
    if(f == NULL){
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }

    int begin = 5000;
    int tests = 12;
    for(int j = 0; j < tests; j++){
        int length = power(2, j) * begin;

        printf("Tamanho do vetor: %d\n", length);
        fprintf(f, "Tamanho do vetor: %d\n", length);

        for(int i = 0; i < QTDALGORITMOS; i++){
            int* array = create_random_array(length);
            // int* array = create_sorted_array(length);
            // int* array = create_inverted_array(length);

            double time = timer(sort_functions[i], array, length);

            printf("%s: %.3lf s\n", sort_names[i], time);
            fprintf(f, "%s: %.3lf s\n", sort_names[i], time);

            free_array(array);
        }

        printf("\n");
        fprintf(f, "\n");
    }

    fclose(f);
    return 0;
}

int power(int base, int exponent){
    if(exponent == 0) return 1;

    int result = 1;
    for(int i = 0; i < exponent; i++){
        result *= base;
    }

    return result;
}