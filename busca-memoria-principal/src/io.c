#include "../include/io.h"

#define FALSE 0
#define TRUE 1


String* read_txt(char* fileName){
    FILE *f = fopen(fileName, "r");

    if(f == NULL){
        printf("An Error has ocurred\n");
        exit(1);
    }

    int size;
    fscanf(f, "%d\n", &size);
    
    char* str = (char*) malloc(sizeof(char) * (size + 1));

    char aux;
    int to_jump = FALSE, j = 0;

    while(TRUE){
        fscanf(f, "%c", &aux);
        if(feof(f)){
            if(to_jump == TRUE){
                j--;
                str[j] = '\0';
            }
            
            break;
        } 
        
        if((aux == ' ' && to_jump == TRUE) || aux == '\n'){
            if(aux == '\n'){
                if(to_jump == FALSE){
                    str[j] = ' ';
                    j++;
                    str[j] = '\0';
                }
                to_jump = TRUE;
            }
            
            continue;
        
        } else if(aux == ' ' && to_jump == FALSE){
            to_jump = TRUE;
        
        } else{
            to_jump = FALSE;
        }

        str[j] = aux;
        j++;
        str[j] = '\0';
    }

    String* string = create_string(str);
    free(str);
    fclose(f);
    return string;
}

void split(char** argv, int* control_keys, char* fileName, int* context, char* query){
    for(int i = 1; i < strlen(argv[1]); i++){
        int key = argv[1][i];
        control_keys[key] = TRUE;
    }

    strcpy(fileName, argv[2]);

    *context = atoi(argv[3]);

    strcpy(query, argv[4]);
}