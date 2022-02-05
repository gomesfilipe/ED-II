#include "../include/io.h"

typedef Report* (*fptr) (Array*, int);
#define TAM 123 // caractere z é 122 na tabela ascii
#define QTDALGORITHMS 5  
#define FALSE 0
#define TRUE 1

// void split(char** argv, char* alg, char* report, int* k, char* fileName){
//     char alg_and_report[100];
//     strcpy(alg_and_report, argv[1]);
//     *alg  = alg_and_report[2];
//     *report = alg_and_report[1];

//     *k = atoi(argv[2]);  //Quantity of element to sort

//     strcpy(fileName, argv[3]);
// }

void split(char** argv, int* control_keys, int* k, char* fileName){
    for(int i = 1; i < strlen(argv[1]); i++){
        int key = argv[1][i];
        control_keys[key] = TRUE;
        //printf("chave: [%c]\n", );
    }

    *k = atoi(argv[2]);  //Quantity of element to sort

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

// void print_output(Report* report, int number, char* fileName){
//     switch (number){
//         case '1': print_k_elements(report); break;
//         case '2': print_statistics(report); break;
//         case '3': print_date(report, fileName); break;

//         default:
//             printf("Invalid argument.\n"); 
//             exit(1);
//     }
// }

void print_output(Report* report, int* control_keys, char* fileName){
    if(control_keys['1'] == TRUE) print_k_elements(report);
    if(control_keys['2'] == TRUE) print_statistics(report);
    if(control_keys['3'] == TRUE) print_date(report, fileName);
}

void build_report(Array* array, int k, int* control_keys, char* fileName){
    int keys[QTDALGORITHMS] = {'s', 'i', 'e', 'q', 'h'};

    if(control_keys['a'] == TRUE){
        fptr sort[QTDALGORITHMS] = {
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
                //printf("key: %c\n", key);
                Report* r = table[key](array, k);
                print_output(r, control_keys, fileName);
                free_report(r);
            }
        }
        
        free_dispatch_table(table);
    }
}

// void build_report(Array* array, int k, int number, char alg, char* fileName){
//     if(alg == 'a'){
//         fptr sort[QTDALGORITHMS] = {
//             partial_selection_sort, 
//             partial_insertion_sort, 
//             partial_shell_sort, 
//             partial_quick_sort, 
//             partial_heap_sort
//         };
        
//         for(int i = 0; i < QTDALGORITHMS ; i++){
//             Array* new = copy_array(array);
//             Report* r = sort[i](new, k);
//             print_output(r, number, fileName);
//             free_array(new);
//             free_report(r);
//         }
    
//     }else if(alg == 's' || alg =='i' || alg == 'e' || alg == 'h' || alg == 'q'){
//         fptr* table = dispatch_table();
//         //printf("PONTEIRO: [%p]\n", table[alg]);
//         Report* r = table[alg](array, k);
//         print_output(r, number, fileName);
//         free_dispatch_table(table);
//         free_report(r);
    
//     } else{
//         printf("Invalid argument.\n");
//         exit(1);
//     }
// }
