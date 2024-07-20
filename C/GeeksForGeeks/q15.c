#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO: look into juggling algorithm: https://www.geeksforgeeks.org/array-rotation/

//O(n*D) time 
//O(1) space
void rotateLeft(int arr[], int size, int numbertorotate) {
    for (int i = 0; i < numbertorotate; i++){
        int* current = arr;
        int* next = arr+1;
        int temp;
        int last = arr[0];
        for(int j = 0; j < size; j++){
            // swap each adjacent element
            temp = *current;
            *current = *next;
            *next = temp;

            current++;
            next++;
        }
        // put first element back at the last
        arr[size-1] = last;
    }
}

// Q15: Write a Program to rotate the array to the left.
int main(int argc, char** argv) {
    // let argv[1] be the array seperated by commas for practise
    // e.g. ./a.out "1,2,3,4"
    int* arr = (int*) malloc(0);
    char* token;
    char delimiter[] = ",";

    // read into dynamically allocated array
    char test[] = "1,2,3,4";
    int size = 0;
    token = strtok(test, delimiter);
    while(token != NULL){
        int num = strtol(token, NULL, 10);
        arr = (int*) realloc(arr, sizeof(int) * (++size));
        arr[size - 1] = num;
        token = strtok(NULL, delimiter);
    }

    rotateLeft(arr, size, 2);

    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    putchar('\n');
    free(arr);
}