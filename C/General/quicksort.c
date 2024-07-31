#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

//https://www.youtube.com/watch?v=0jDiBM68NGU

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int arr[], int low, int high) {
    // Assume pivot is the last element in the partition
    int pivotValue = arr[high];

    // Difficult to explain please see 11:34 minute mark of the video.
    // Basically, swaps happen so that all values less than or equal to the pivot
    // end up before index i, and all values greater than end up on the right of i.
    int i = low;
    for (int j = low; j < high; j++) {
        if(arr[j] <= pivotValue) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }

    // Place the pivot value into the index of i
    swap(&arr[i], &arr[high]);

    // Return new location of pivot
    return i;
}

void quicksortRecursion(int arr[], int low, int high) {
    // Base case when we run out of size
    if (low >= high) {
        return;
    }

    // Get the index of the pivot
    int pivotIndex = partition(arr, low, high);
    
    // Recurse through the left side of the array up to the pivot
    quicksortRecursion(arr, low, pivotIndex - 1);

    // Recurse through the right side of the array beyond the pivot
    quicksortRecursion(arr, pivotIndex + 1, high);
}

void quicksort(int arr[], int size){
    // Sort entire array bounds
    quicksortRecursion(arr, 0, size - 1);
}

int main(int argc, char** argv){
    int arr[] = {10,11,23,44,8,15,3,9,12,45,56,45,45};
    int size = sizeof(arr)/sizeof(int);

    quicksort(arr, size);

    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    putchar('\n');

    return 0;
}
