#include "../include/file.h"

struct file {
    int size;
};

File* create_file(int size) {
    File* file = (File*) malloc(sizeof(File));
    file->size = size;
    return file;
}

void free_file(File* file) {
    free(file);
}

void print_file(File* file) {
    printf("%d\n", file->size);
}

int get_size(File* file) {
    return file->size;
}
