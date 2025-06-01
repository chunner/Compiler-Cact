#include <stdio.h>

void print_int(int x) {
    printf("%d", x);
    fflush(stdout);
}

void print_float(float x) {
    printf("%g", x);
    fflush(stdout);
}

void print_char(char x) {
    printf("%c", x);
    fflush(stdout);
}

int get_int(void) {
    int x;
    if (scanf("%d", &x) != 1) {
        return 0;
    }
    return x;
}

float get_float(void) {
    float x;
    if (scanf("%f", &x) != 1) {
        return 0.0f;
    }
    return x;
}

char get_char(void) {
    char x;
    if (scanf(" %c", &x) != 1) {
        return '\0';
    }
    return x;
}