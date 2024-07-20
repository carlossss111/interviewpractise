#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//O(n) time
//O(1) space
int findmax(int* arr, int size){
    //O(n)
    int max = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

//O(n) time
//O(1) space
int findmin(int* arr, int size){
    int min = __INT_MAX__;
    for(int i = 0; i < size; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }
    return min;
}

// Q13: Write a Program to find the maximum and minimum of an Array.
int main(int argc, char** argv){
    // let argv[1] be the array seperated by commas for practise
    // e.g. ./a.out "1,2,3,4"
    int* arr = (int*) malloc(0);
    char* token;
    char delimiter[] = ",";

    // read into dynamically allocated array
    int size = 0;
    token = strtok(argv[1], delimiter);
    while(token != NULL){
        int num = strtol(token, NULL, 10);
        arr = (int*) realloc(arr, sizeof(int) * (++size));
        arr[size - 1] = num;
        token = strtok(NULL, delimiter);
    }

    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    putchar('\n');

    printf("min = %d\n", findmin(arr, size));
    printf("max = %d\n", findmax(arr, size));

    free(arr);
    return 0;
}