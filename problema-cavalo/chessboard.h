#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <stdio.h>
#include <stdlib.h>
#include "horse.h"

typedef struct chessboard Chessboard;

Chessboard* create_chessboard(int rows, int columns, int i_initial, int j_initial);

void free_chessboard(Chessboard* b);

int total_positions(Chessboard* b);

int visited_position(Chessboard* b, int i, int j);

int valid_position(Chessboard* b, int i, int j);

int move_horse(Chessboard* b, int new_i, int new_j);

int move_left_up(Chessboard* b);

int move_left_down(Chessboard* b);

int move_right_up(Chessboard* b);

int move_right_down(Chessboard* b);

int move_up_left(Chessboard* b);

int move_up_right(Chessboard* b);

int move_down_left(Chessboard* b);

int move_down_right(Chessboard* b);

int search_solution(Chessboard* b);

void print_chessboard(Chessboard* b);

#endif
