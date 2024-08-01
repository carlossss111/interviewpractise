#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TO DO: pop_back(), insert(), remove()

typedef struct Vector {
    int* arr;
    int arr_size;
    int malloc_size;

    void (*push_back) (struct Vector* self, int element);
    int* (*at) (struct Vector* self, int index);
}Vector;

// O(n) memory, O(1) amortized time
void push_back(struct Vector* self, int element) {
    // Memory Management, double when hit
    if(self->malloc_size == 0) {
        self->malloc_size = 1;
        self->arr = (int*) malloc(sizeof(int) * 1);
    }
    else if(self->malloc_size == self->arr_size) {
        self->malloc_size *= 2;
        self->arr = (int*) realloc(self->arr, sizeof(int) * self->malloc_size);
    }

    // Insert
    self->arr_size++;
    self->arr[self->arr_size - 1] = element;
}

// O(1) time
int* at(struct Vector* self, int index) {
    if(index >= self->arr_size || index < 0){
        return NULL;
    }
    return &self->arr[index];
}

Vector* createVector() {
    Vector* vec = (Vector*) malloc(sizeof(Vector));
    vec->push_back = push_back;
    vec->at = at;

    vec->malloc_size = 0;
    vec->arr_size = 0;
    return vec;
}

void deleteVector(Vector* vec) {
    free(vec->arr);
    free(vec);
}

int main(int argc, char** argv) {
    Vector* vec = createVector(sizeof(int));
    for(int i = 0; i < 10000; i++){
        vec->push_back(vec, i);
    }
    for(int i = -1; i < 10001; i++){
        int* res = vec->at(vec, i);
        if(res){
            printf("%d ", *res);
        }
        else{
            printf("NaN ");
        }
    }
    putchar('\n');
    deleteVector(vec);
    return 0;
}