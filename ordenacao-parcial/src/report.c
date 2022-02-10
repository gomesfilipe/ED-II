#include "../include/report.h"

struct report {
    char* algorithm;
    int original_size;
    unsigned long long comparation;
    unsigned long long swap;
    double time;
    Array* topK;
};

Report* create_report(int k, char* algorithm, int original_size){
    Report* report = (Report*) malloc(sizeof(Report));
    report->algorithm = strdup(algorithm);
    report->original_size = original_size;
    report->comparation = 0;
    report->swap = 0;
    report->time = 0;
    report->topK = create_array(k);
    return report;
}

void free_report(Report* report){
    free(report->algorithm);
    free_array(report->topK);
    free(report);
}

void increment_comparation(Report* report){
    report->comparation++;
}

void increment_swap(Report* report){
    report->swap++;
}

void set_time(Report* report, double time){
    report->time = time;
}

void insert_element_topK(Report* report, int element){
    insert_element_array(report->topK, element);
}

void fill_array_topK(Report* report, Array* array, int is_heap){
    int k = get_size(report->topK);
    int size = get_size(array);
    
    if(k > size) return;

    if(is_heap){
        for(int i = size - 1; i >= size - k; i--){
            insert_element_topK(report, get_element(array, i));
        }

    }else{
        for(int i = 0; i < k ; i++){
            insert_element_topK(report, get_element(array, i));  
        }
    }
}

void print_statistics(Report* report){
    printf("Algoritmo: %s\n", report->algorithm);
    printf("Tempo de CPU: %.6f\n", report->time);
    printf("Comparações: %llu\n", report->comparation);
    printf("Trocas: %llu\n", report->swap);
    printf("\n");
}

void print_k_elements(Report* report){
    for(int i = 0; i < get_size(report->topK) ; i++){
        printf("%d\n", get_element(report->topK, i));
    }
    printf("\n");
}

void print_date(Report* report, char* fileName){    
    printf("%s    ", report->algorithm ); 
    printf("%s    ", fileName);
    printf("%d    ", report->original_size);
    printf("%d    ", get_size(report->topK));
    printf("%llu    ", report->comparation);
    printf("%llu    ", report->swap);
    printf("%.5f    \n\n", report->time);
}
