#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Binary search is where you split a sorted array and go higher or lower, then split that, etc etc.
int binarysearch(int* arr, int size, int target){

    int counter = 0;

    size -= 1;
    int i = size/2;
    for(;;){
        counter++;

        size /= 2;
        if (arr[i] == target){
            printf("Took %d trie(s).\n", counter);
            return i;
        }
        else if (arr[i] < target){
            i += size/2;
        }
        else if (arr[i] > target){
            i -= size/2;
        }
        else if (size == 1){
            return -1;
        }
    }

    return -1;
}

int betterbinarysearch(int* arr, int size, int target){
    int lindex = 0;
    int rindex = size - 1;
    int midpoint;
    int tries = 0;

    while (lindex <= rindex) {
        tries++;
        midpoint = lindex + (rindex - lindex) / 2;

        if(arr[midpoint] == target){
            printf("Took %d trie(s).\n", tries);
            return midpoint;
        }

        else if (arr[midpoint] < target) {
            lindex = midpoint + 1;
        }

        else if (arr[midpoint] > target) {
            rindex = midpoint - 1;
        }
    }

    return -1;
}

// there is also a recursive one that im not interested in

// Q17: Write a Program to search elements in an array (using Binary Search).
int main(int argc, char** argv) {
    int target;
    if(argc > 1)
        target = strtol(argv[1], NULL, 10);
    else
        target = 20;
    int sortedarr[] = {0,1,2,3,4,5,6,7,8,9  ,10, 11,12,13,14,15,16,17,18,19,20};
    int size = sizeof(sortedarr) / sizeof(int);

    int indexfound = betterbinarysearch(sortedarr, size, target);
    if (indexfound == -1){
        printf("Element not found!\n");
    }
    else{
        printf("Element found at index %d.\n", indexfound);
    }

    return 0;
}