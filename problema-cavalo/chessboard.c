#include "chessboard.h"

#define NOTFOUND 0
#define FOUND 1

#define TRUE 1
#define FALSE 0
#define QTDMOV 8

typedef int (*fptr) (Chessboard*);

fptr movements[QTDMOV] = {move_left_up, move_left_down, move_right_up, move_right_down, 
                          move_up_left, move_up_right, move_down_left, move_down_right};

struct chessboard{
    int rows;
    int columns;
    int visits;
    int** board;
    Horse* horse;
};

Chessboard* create_chessboard(int rows, int columns, int i_initial, int j_initial){
    Chessboard* b = (Chessboard*) malloc(sizeof(Chessboard));
    b->rows = rows;
    b->columns = columns;
    b->visits = 1;
    b->horse = create_horse(i_initial, j_initial);

    b->board = (int**) malloc(sizeof(int*) * b->rows);

    for(int i = 0; i < b->rows; i++){
        b->board[i] = (int*) calloc(b->columns, sizeof(int));
    }

    b->board[i_initial][j_initial] = 1;

    return b;
}

void free_chessboard(Chessboard* b){
    free_horse(b->horse);

    for(int i = 0; i < b->rows; i++){
        free(b->board[i]);
    }

    free(b->board);
    free(b);
}

int total_positions(Chessboard* b){
    return b->columns * b->rows;
}

int visited_position(Chessboard* b, int i, int j){
    return b->board[i][j] != 0;
}

int valid_position(Chessboard* b, int i, int j){
    return i >= 0 && i < b->rows && j >= 0 && j < b->columns && !visited_position(b, i, j);
}

int move_horse(Chessboard* b, int new_i, int new_j){
    if(valid_position(b, new_i, new_j)){
        b->horse = set_i_horse(b->horse, new_i);
        b->horse = set_j_horse(b->horse, new_j);
        
        b->visits++;
        b->board[new_i][new_j] = b->visits;

        return TRUE; // Cavalo moveu.
    }

    return FALSE; // Cavalo não pode mover.
}

int move_left_up(Chessboard* b){
    int new_j = get_j_horse(b->horse) - 1;
    int new_i = get_i_horse(b->horse) - 2;
    
    return move_horse(b, new_i, new_j);
}

int move_left_down(Chessboard* b){
    int new_j = get_j_horse(b->horse) - 1;
    int new_i = get_i_horse(b->horse) + 2;
    
    return move_horse(b, new_i, new_j);
}

int move_right_up(Chessboard* b){
    int new_j = get_j_horse(b->horse) + 1;
    int new_i = get_i_horse(b->horse) - 2;
    
    return move_horse(b, new_i, new_j);
}

int move_right_down(Chessboard* b){
    int new_j = get_j_horse(b->horse) + 1;
    int new_i = get_i_horse(b->horse) + 2;
    
    return move_horse(b, new_i, new_j);
}

int move_up_left(Chessboard* b){
    int new_j = get_j_horse(b->horse) - 2;
    int new_i = get_i_horse(b->horse) - 1;
    
    return move_horse(b, new_i, new_j);
}

int move_up_right(Chessboard* b){
    int new_j = get_j_horse(b->horse) + 2;
    int new_i = get_i_horse(b->horse) - 1;
    
    return move_horse(b, new_i, new_j);
}

int move_down_left(Chessboard* b){
    int new_j = get_j_horse(b->horse) - 2;
    int new_i = get_i_horse(b->horse) + 1;
    
    return move_horse(b, new_i, new_j);
}

int move_down_right(Chessboard* b){
    int new_j = get_j_horse(b->horse) + 2;
    int new_i = get_i_horse(b->horse) + 1;
    
    return move_horse(b, new_i, new_j);
}

int search_solution(Chessboard* b){
    int current_i = get_i_horse(b->horse);
    int current_j = get_j_horse(b->horse);
    int success, status;

    for(int i = 0; i < QTDMOV; i++){
        success = movements[i](b);

        if(success){
            if(b->visits == total_positions(b)){
                return FOUND;
            
            } else{
                status = search_solution(b);

                if(status == FOUND){
                    return FOUND;
                
                } else{
                    b->visits--;
                    b->horse = set_i_horse(b->horse, current_i);
                    b->horse = set_j_horse(b->horse, current_j);
                }
            }
        }
    }

    b->board[current_i][current_j] = 0;
    return NOTFOUND;
}

void print_chessboard(Chessboard* b){
    for(int i = 0; i < b->rows; i++){
        for(int j = 0; j < b->columns; j++){
            printf("%02d ", b->board[i][j]);
        }

        printf("\n");
    }
}
