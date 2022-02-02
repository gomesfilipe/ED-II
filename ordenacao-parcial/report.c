#include "report.h"

struct report {
    int comparation;  
    int swap;
    double time;
    Array* topK;
};

Report* create_report(int k){
    Report* report = (Report*) malloc(sizeof(Report));
    report->comparation = 0;
    report->swap = 0;
    report->time = 0;
    report->topK = create_array(k);

    return report;
}

void free_report(Report* report){
    free(report->topK);
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

void print_report(Report* report){
    printf("Tempo de CPU: %.6f\n", report->time);
    printf("Comparações: %d\n", report->comparation);
    printf("Trocas: %d\n", report->swap);
    print_array(report->topK);
}