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
    //A menina que roubava livros
    //  A menina que roubava livros
    char str[size];
    char aux;
    int to_jump = FALSE;

    for(int i = 0, j = 0; i < size; i++){
        fscanf(f, "%c", &aux);
        
        // printf("[%c] ", aux);
        
        if((aux == ' ' && to_jump == TRUE) || aux == '\n'){
            continue;
        
        } else if(aux == ' ' && to_jump == FALSE){
            to_jump = TRUE;
        
        } else{
            to_jump = FALSE;
        }

        str[j] = aux;
        
        printf(".%c.", str[j]);
        j++;
        str[j] = '\0';
    }

    fclose(f);
    String* string = create_string(str);
    return string;
}
