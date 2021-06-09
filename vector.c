#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void **pt;
    size_t capacity;
    size_t length;
} Vector;


void push