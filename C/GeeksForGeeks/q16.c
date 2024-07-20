#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TO DO: look into binary search alternative https://www.geeksforgeeks.org/remove-duplicates-sorted-array/

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// O(n) time, O(1) space
int* inplace(int* arr, int* size){
    int* uniqueptr = arr;
    int* nextptr = arr;

    // loop through with the next ptr
    // when non-duplicates are found, update the unique ptr and swap them in
    int i = 0;
    int j = 0;
    while(i < *size){
        if(*uniqueptr != *nextptr){
            uniqueptr++;
            j++;
            swap(nextptr, uniqueptr);
        }
        nextptr++;
        i++;
    }

    *size = j + 1;
    arr = (int*) realloc(arr, sizeof(int) * (*size));
    return arr; 
    // we MUST return the pointer after realloc()
    // this is because the pointer pointed to by the arg arr is different
    // perhaps realloc should be in the main loop anyway, but I'll leave it here to demonstrate a point.
}

// Q16: Write a Program to remove duplicates from the Sorted array.
int main(int argc, char** argv) {
    // Input
    int size = argc - 1;
    int* arr = (int*) malloc(sizeof(int) * size);
    for(int i = 0; i < size; i++) {
        arr[i] = strtol(argv[i+1], NULL, 10);
    }

    arr = inplace(arr, &size);

    // Output
    printf("New size = %d\n", size);
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    putchar('\n');

    free(arr);
    return 0;
}