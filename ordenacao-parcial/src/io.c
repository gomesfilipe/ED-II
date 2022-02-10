#include "../include/io.h"

typedef Report* (*fptr) (Array*, int);
#define TAM 123 // Caractere z é 122 na tabela ascii.
#define QTDALGORITHMS 5  
#define FALSE 0
#define TRUE 1

void split(char** argv, int* control_keys, int* k, char* fileName){
    for(int i = 1; i < strlen(argv[1]); i++){
        int key = argv[1][i];
        control_keys[key] = TRUE;
    }

    *k = atoi(argv[2]);

    strcpy(fileName, argv[3]);
}

Array* read_file(char* fileName){
    FILE* f = fopen(fileName, "r");
    if(f == NULL){
        printf("File not found.\n");
        exit(1);
    }

    int size;
    fscanf(f, "%d\n", &size);
    Array* array = create_array(size);

    int element;
    for(int i = 0; i < size; i++){
        fscanf(f, "%d\n", &element);
        insert_element_array(array, element);
    }

    fclose(f);
    return array;
}

static fptr* dispatch_table(){
    // Cria uma tabela de dispersão com ponteiros das funções de ordenação. 
    fptr* table = (fptr*) malloc(sizeof(fptr) * TAM);

    table['s'] = partial_selection_sort;
    table['i'] = partial_insertion_sort;
    table['e'] = partial_shell_sort;
    table['h'] = partial_heap_sort;
    table['q'] = partial_quick_sort;

    return table;
}

static void free_dispatch_table(fptr* table){
    free(table);
}

void print_output(Report* report, int* control_keys, char* fileName){
    if(control_keys['1'] == TRUE) print_k_elements(report);
    if(control_keys['2'] == TRUE) print_statistics(report);
    if(control_keys['3'] == TRUE) print_date(report, fileName);
}

void build_report(Array* array, int k, int* control_keys, char* fileName){
    int keys[QTDALGORITHMS] = {'s', 'i', 'e', 'q', 'h'}; // Para iterar na tabela de dispersão.

    if(control_keys['a'] == TRUE){
        fptr sort[QTDALGORITHMS] = { // Iterar neste vetor para executar todos os algoritmos de ordenação.
            partial_selection_sort, 
            partial_insertion_sort, 
            partial_shell_sort, 
            partial_quick_sort, 
            partial_heap_sort
        };
        
        for(int i = 0; i < QTDALGORITHMS ; i++){
            Array* new = copy_array(array);
            Report* r = sort[i](new, k);
            print_output(r, control_keys, fileName);
            free_array(new);
            free_report(r);
        }
    
    }else {
        fptr* table = dispatch_table();
        
        for(int i = 0; i < QTDALGORITHMS; i++){
            int key = keys[i];

            if(control_keys[key] == TRUE){
                Report* r = table[key](array, k);
                print_output(r, control_keys, fileName);
                free_report(r);
            }
        }
        
        free_dispatch_table(table);
    }
}
