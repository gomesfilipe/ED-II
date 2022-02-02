#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "partial_sorting.h"
#include "report.h"

int main(){
    Array* array = create_array(20);
    fill_array(array);
    
    print_array(array);

    // Report* r1 = partial_selection_sort(array, 5);
    //Report* r2 = partial_insertion_sort(array, 5);
    //Report* r3 = partial_quick_sort(array, 5);
    //Report* r4 =partial_shell_sort(array, 5); //esta errado
    Report* r5 = partial_heap_sort(array, 5);

    // heapSort(array);
    
    print_array(array);
    printf("\n-------------------------------\n\n");
    print_report(r5);

    free_array(array);
    free_report(r5);
    return 0;

}

/*

  Como a impressao deve ser feita
  [algoritmo	  arquivo	  tam.	 T(top)	 comp. 	trocas	tempo(s)]
  seleção	  ./in/5.txt	5	  5	      x	        y	  0.00001

*/
