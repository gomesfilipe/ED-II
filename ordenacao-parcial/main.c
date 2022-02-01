#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "partial_sorting.h"

int main(){
    Array* array = create_array(20);
    fill_array(array);
    
    print_array(array);

    //partial_selection_sort(array, 5);
    // partial_insertion_sort(array, 5);
    // partial_quick_sort(array, 5);
    partial_shell_sort(array, 5);

    print_array(array);

    free_array(array);
    return 0;

}

    //na main chamar tudo

    //sort.h
    //sort.c

    //reports
    /* O que o trabalho pede:
    CPU time
    qtas comparações  
    qts trocas  

    Como a impressao deve ser feita
    [algoritmo	  arquivo	  tam.	 T(top)	 comp. 	trocas	tempo(s)]
		seleção	  ./in/5.txt	5	  5	      x	        y	  0.00001

    */