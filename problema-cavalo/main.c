#include <stdio.h>
#include <stdlib.h>
#include "horse.h"
#include "chessboard.h"

int main(){
    int rows = 8, columns = 8, i_initial = 0, j_initial = 1;

    for(int i = 1; i < 4; i++){
        for(int j = i; j < 4; j++){
            i_initial = i;
            j_initial = j;
            Chessboard* b = create_chessboard(rows, columns, i_initial, j_initial);

            int has_solution = search_solution(b);

            if(has_solution){
                // print_chessboard(b);
                printf("Solution starting at [%2d ; %2d]\n", i_initial, j_initial);
            } else{
                printf("No solution.\n");
            }

            free_chessboard(b);
        }
    }
    
    return 0;
}
