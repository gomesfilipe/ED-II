#include <stdio.h>
#include <stdlib.h>
#include "../include/io.h"
#include "../include/str.h"
#include "../include/suffix.h"

#define TAM 123 // Pegar o 'z' na tabela ascii.

int main(int argc, char** argv) { 
    // if(argc != 5){
    //     printf("Incorrect number of parameters!\n");
    //     return 1;
    // }
    
    // int control_keys[TAM] = {FALSE};
    // char fileName[TAM];
    // int context;
    // char* query[TAM];
    // void split(argv, control_keys, fileName, &context, query);

    // String* string = read_txt("input/teste.txt");
    // String* string = read_txt("input/teste2.txt");
    String* string = read_txt("input/tale.txt");
    // String* string = read_txt("input/abra.txt");

    Suffix** array = create_suf_array(string, get_len(string));
    // print_suf_array(array, get_len(string));

    // printf("\n\n------------------\n\n");
    sort_suf_array(array, get_len(string));
    // heap_sort_suf_array(array, get_len(string));
    //print_suf_array(array, get_len(string));

    String* query = create_string("majesty");

    int position = search_first_query(array, get_len(string), query);

    print_binary_search(array, get_len(string), position, 15 , query);

    destroy_suf_array(array, get_len(string));
    destroy_string(string);
    destroy_string(query);

    return 0;
}
