#include "str.h"

struct string {
    char *c;
    int len;
};

char* get_c(String* str){
    return str->c;
}

int get_len(String* str){
    return str->len;
}

static int mystrlen(char *a) {
    int i;
    for (i = 0; a[i] != '\0'; i++);
    return i;
}

String* create_string(char *a) {
    String *s = (String*) malloc(sizeof(String));
    s->len = mystrlen(a);
    s->c = malloc((s->len + 1) * sizeof(char)); // Alteramos para alocar 1 espaço a mais para o \0.
    for (int i = 0; i < s->len; i++) {
        s->c[i] = a[i];
    }
    s->c[s->len] = '\0'; // Colocando \0 na última posição.
    return s;
}

void destroy_string(String *s) {
    free(s->c);
    free(s);
}

void print_string(String *s) {
    for (int i = 0; i < s->len; i++) {
        printf("%c", s->c[i]);
    }
}

int compare(String *s, String *t) {
    return compare_from(s, t, 0);
}

int compare_from(String *s, String *t, int d) {
    int min = s->len < t->len ? s->len : t->len;
    for (int i = d; i < min; i++) {
        if (s->c[i] < t->c[i]) { return -1; }
        if (s->c[i] > t->c[i]) { return  1; }
    }
    return s->len - t->len;
}

String** create_str_array(int N) {
    String* *a = malloc(N * sizeof(String*));
    return a;
}

void destroy_str_array(String* *a, int N) {
    for (int i = 0; i < N; i++) {
        destroy_string(a[i]);
    }
    free(a);
}

void print_str_array(String* *a, int N) {
    for (int i = 0; i < N; i++) {
        print_string(a[i]);
        printf("\n");
    }
}

bool equals_substring(String *text, int from, int to, String *query) {
    //if (query->len < (to - from + 1)) { return false; }
    for (int i = 0; i < query->len; i++) {
        if(tolower(query->c[i]) != tolower(text->c[from + i])) { return false; }
    }
    return true;
}

void print_substring(String *s, int from, int to) {
    for (int i = from; i < to; i++) {
        printf("%c", s->c[i]);
    }
}
