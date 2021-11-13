#include "horse.h"

struct horse{
    int i;
    int j;
};

Horse* create_horse(int i_initial, int j_initial){
    Horse* h = (Horse*) malloc(sizeof(Horse));
    h->i = i_initial;
    h->j = j_initial;
    return h;
}

void free_horse(Horse* h){
    free(h);
}

int get_i_horse(Horse* h){
    return h->i;
}

int get_j_horse(Horse* h){
    return h->j;
}

Horse* set_i_horse(Horse* h, int i){
    h->i = i;
    return h;
}

Horse* set_j_horse(Horse* h, int j){
    h->j = j;
    return h;
}
