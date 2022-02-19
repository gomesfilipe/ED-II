#include "../include/io.h"

#define FALSE 0
#define TRUE 1
#define TAM 500

String* read_txt(char* fileName){
    FILE *f = fopen(fileName, "r");

    if(f == NULL){
        printf("An Error has ocurred\n");
        exit(1);
    }

    int size;
    fscanf(f, "%d\n", &size);
    
    char* str = (char*) malloc(sizeof(char) * (size + 1)); // 1 espaço a mais por causa do \0.

    char aux;
    int to_jump = FALSE, j = 0;

    while(TRUE){
        fscanf(f, "%c", &aux);
        if(feof(f)){
            if(to_jump == TRUE){ // Verificando se o último caractere é um espaço.
                j--;
                str[j] = '\0'; // Se for, coloca um \0 onde ele estava.
            }
            
            break;
        } 
        
        if((aux == ' ' && to_jump == TRUE) || aux == '\n'){
            if(aux == '\n'){ // Colocar um espaço na string quando houver quebra de linha.
                if(to_jump == FALSE){
                    str[j] = ' ';
                    j++;
                    str[j] = '\0';
                }
                to_jump = TRUE;
            }
            
            continue;
        
        } else if(aux == ' ' && to_jump == FALSE){ // Encontrou espaço pela primeira vez, atualizar variável de controle.
            to_jump = TRUE;
        
        } else{ // Resetar variável de controle caso não seja espaço.
            to_jump = FALSE;
        }

        str[j] = aux;
        j++;
        str[j] = '\0'; // Controlando posição do \0 para evitar problemas na criação da string.
    }

    String* string = create_string(str);
    free(str);
    fclose(f);
    return string;
}

static void concat_str(int argc, char** argv, char* query){
    // Auxiliar de command_c. Caso a query tenha espaços, ela estará separada
    // em várias strings no argv. O laço abaixo pega todas elas e as concatena 
    // numa única string.
    for(int i = 4; i < argc; i++){ 
        strcat(query, argv[i]);
        if(i != argc-1 ) {
            strcat(query, " ");
        }
    }
}

static void command_a(int argc, char** argv){
    if(argc != 3){
        printf("Incorrect number of parameters!\n");
        exit(1);
    }

    String* text = read_txt(argv[2]);
    
    int len = get_len(text);
    Suffix** array_suf = create_suf_array(text, len);
    
    print_suf_array(array_suf, len);
    
    destroy_suf_array(array_suf, len);
    destroy_string(text);
}

static void command_o(int argc, char** argv){
    if(argc != 3){
        printf("Incorrect number of parameters!\n");
        exit(1);
    }

    String* text = read_txt(argv[2]);
    
    int len = get_len(text);
    Suffix** array_suf = create_suf_array(text, len);
    
    sort_suf_array(array_suf, len);
    print_suf_array(array_suf, len);
    
    destroy_suf_array(array_suf, len);
    destroy_string(text);
}

static void command_r(int argc, char** argv){
    if(argc != 3){
        printf("Incorrect number of parameters!\n");
        exit(1);
    }
    String* text = read_txt(argv[2]);
    
    int len = get_len(text);

    
    Suffix** array_suf1 = create_suf_array(text, len);
    clock_t start1 = clock();
    sort_suf_array(array_suf1, len);
    clock_t end1 = clock();
    double cpu_time_used1 = ((double) (end1 - start1)) / CLOCKS_PER_SEC;

    Suffix** array_suf2 = create_suf_array(text, len);
    clock_t start2 = clock();
    heap_sort_suf_array(array_suf2, len);
    clock_t end2 = clock();
    double cpu_time_used2 = ((double) (end2 - start2)) / CLOCKS_PER_SEC;
    
    printf("System qsort    %.3f (s)\n", cpu_time_used1);
    printf("My_sort_heapsort    %.3f (s)\n", cpu_time_used2);
    
    destroy_suf_array(array_suf1, len);
    destroy_suf_array(array_suf2, len);
    destroy_string(text);
}

static void command_c(int argc, char** argv){
    if(argc < 5){
        printf("Incorrect number of parameters!\n");
        exit(1);
    }
    
    String* text = read_txt(argv[2]);
   
    int len = get_len(text);
    Suffix** array_suf = create_suf_array(text, len);
    
    int context = atoi(argv[3]);
    char query_aux[TAM] = "";
    concat_str(argc, argv, query_aux);
    String* query = create_string(query_aux);
   
    sort_suf_array(array_suf,len);
    int first = search_first_query(array_suf, len, query);    
   
    print_binary_search(array_suf,  len, first, context, query);
    
    destroy_suf_array(array_suf, len);
    destroy_string(text);
    destroy_string(query);
}

static void command_s(int argc, char** argv){
    if(argc != 4){
        printf("Incorrect number of parameters!\n");
        exit(1);
    }
    
    String* text = read_txt(argv[2]);

    int context = atoi(argv[3]);
 
    int len = get_len(text); 
    Suffix** array_suf = create_suf_array(text, len);
    sort_suf_array(array_suf, len);

    char query_str[TAM];

    while( scanf("%[^\n]", query_str) != 0 ){
        getchar();
        String* query = create_string(query_str);
        int first = search_first_query(array_suf, len, query);

        print_binary_search(array_suf, len, first, context, query);
        printf("\n");
        destroy_string(query);
    }

    destroy_suf_array(array_suf, len);
    destroy_string(text);
}

void main_memory_search(int argc, char** argv){
    if(argc < 3){
        printf("Incorrect number of parameters!\n");
        exit(1);
    }

    switch(argv[1][1]){
        case 'a': command_a(argc, argv); break;
        case 'o': command_o(argc, argv); break;
        case 'r': command_r(argc, argv); break;
        case 'c': command_c(argc, argv); break;
        case 's': command_s(argc, argv); break;
        default: printf("Incorrect command.\n"); exit(1);
    }
}
