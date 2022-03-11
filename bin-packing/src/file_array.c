#include "../include/file_array.h"

struct fileArray {
    int size;
    int length;
    File** files;
};

FileArray* create_file_array(int size) {
    FileArray* fileArray = (FileArray*) malloc(sizeof(FileArray));
    fileArray->size = size;
    fileArray->length = 0;
    fileArray->files = (File**) malloc(sizeof(File*) * size);
    return fileArray;
}

void free_file_array(FileArray* fileArray) {
    for(int i = 0; i < fileArray->length; i++) {
        free_file(fileArray->files[i]);
    }
    free(fileArray->files);
    free(fileArray);
}

void print_file_array(FileArray* fileArray) {
    for(int i = 0; i < fileArray->length; i++) {
        print_file(fileArray->files[i]);
    }
    printf("\n");
}

void insert_file_in_array(FileArray* fileArray, File* file) {
    if(fileArray->length == fileArray->size) return;

    fileArray->files[fileArray->length] = file;
    fileArray->length++;
}

FileArray* reader(char* fileName) {
    FILE* f = fopen(fileName, "r");

    if(f == NULL) {
        printf("File not found.\n");
        exit(1);
    }

    int sizeArray;
    fscanf(f, "%d\n", &sizeArray);

    FileArray* fileArray = create_file_array(sizeArray);

    for(int i = 0; i < sizeArray; i++) {
        int sizeFile;
        fscanf(f, "%d\n", &sizeFile);
        File* file = create_file(sizeFile);
        insert_file_in_array(fileArray, file);
    }

    fclose(f);
    return fileArray;
}

static int compare(const void * a, const void * b) {
    File* fileA = *(File**) a;
    File* fileB = *(File**) b;

    return get_size(fileB) - get_size(fileA);
}

void sort_array(FileArray* fileArray) {
    qsort(fileArray->files, fileArray->length, sizeof(File*), compare);
}
