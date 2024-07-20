#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUTS 10

// Q18: Write a Program to create a dynamic array in C.
// In this problem, you have to write a program to create an array of size n dynamically then take n 
// elements of an array one by one by the user. Print the array elements.
int main(int argc, char** argv){
    int* arr = (int*) malloc(0);
    int size = 0;

    for(int i = 0; i < MAX_INPUTS; i++){
        char strin[32];
        if(fgets(strin, sizeof(strin), stdin) == NULL){
            fprintf(stderr, "Failed to take input!\n");
            break;
        }
        if(strcmp(strin, "q\n") == 0){
            break;
        }

        size++;
        arr = (int*) realloc(arr, sizeof(int) * size);
        arr[i] = strtol(strin, NULL, 10);
    }

    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    putchar('\n');

    free(arr);
}
