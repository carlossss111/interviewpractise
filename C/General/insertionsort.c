#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//https://www.youtube.com/watch?v=Tz7vBodZqo8

// left side of arr 
void insertionsort(int arr[], int length){
    for(int i = 1; i < length; i++){
        int key = arr[i];
        int j = i - 1; // put j left of i.
        while(j >= 0 && arr[j] > key){ 
            arr[j+1] = arr[j]; // shift the elements over until in the right place before i
            j--;
        }
        arr[j+1] = key; // move key along
    }
}

int main(int argc, char** argv){
    int arr[] = {8,4,9,5,7,6,3,2, 1};
    int size = sizeof(arr)/sizeof(int);

    insertionsort(arr, size);

    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    putchar('\n');

    return 0;
}