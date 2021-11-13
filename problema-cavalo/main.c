#include <stdio.h>
#include <stdlib.h>
#include "horse.h"
#include "chessboard.h"

int main(int argc, char** argv){
    int rows = atoi(argv[1]);
    int columns = atoi(argv[2]);
    int i_initial = atoi(argv[3]);
    int j_initial = atoi(argv[4]);

    if(argc != 5 || rows == 0 || columns == 0 || i_initial < 0 || j_initial < 0 ||
       i_initial >= rows || j_initial >= columns){
        printf("Argumentos incorretos.\n");
        exit(1);
    }

    Chessboard* b = create_chessboard(rows, columns, i_initial, j_initial);

    printf("Wait for the program to calculate the solution (depending on the input, it may take a while).\n\n");

    int has_solution = search_solution(b);

    if(has_solution){
        printf("Solution starting at (%02d ; %02d).\n\n", i_initial, j_initial);
        print_chessboard(b);
    } else{
        printf("No solution.\n");
    }

    free_chessboard(b);
    return 0;
}
