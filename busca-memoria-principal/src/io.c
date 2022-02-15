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
    
    char* str = (char*) malloc(sizeof(char) * size);

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

    fclose(f);
    String* string = create_string(str);
    free(str);
    return string;
}
