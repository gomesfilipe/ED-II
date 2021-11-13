#ifndef HORSE_H
#define HORSE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct horse Horse;

Horse* create_horse(int i_initial, int j_initial);

void free_horse(Horse* h);

int get_i_horse(Horse* h);

int get_j_horse(Horse* h);

Horse* set_i_horse(Horse* h, int i);

Horse* set_j_horse(Horse* h, int j);

#endif
