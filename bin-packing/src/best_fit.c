#include "../include/best_fit.h"

#define SUCCESS 1
#define FAIL 0

int best_fit_in_order(FileArray* fileArray) {
    return 1;
}

int best_fit_descending(FileArray* fileArray) {
    sort_array(fileArray);
    return best_fit_in_order(fileArray);
}
