#include <stdio.h>
#include <stdlib.h>
#include "../include/io.h"
#include "../include/str.h"
#include "../include/suffix.h"

int main(int argc, char** argv) { 
    //String* string = read_txt("input/abra.txt");
    
    // String* string = read_txt("input/teste.txt");
    String* string = read_txt("input/teste2.txt");


    printf("\n\n ------- main -------- \n\n");
    print_string(string);

    destroy_string(string);

    return 0;
}
