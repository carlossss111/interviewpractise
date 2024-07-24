#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Two Methods:
First, we could increment the rightmost int, check if it is 9, then increment the next.
Alternatively, we could convert it all into an int, then change +1, then convert it to an array again.
*/

void printdigits(int* digits, int len){
    for(int i = 0; i < len; i++){
        printf("%d ", digits[i]);
    }
    putchar('\n');
}

void increment(int* digits, int len, int index){
    digits[index]++;
    if(digits[index] == 10){
        digits[index] = 0;
        increment(digits, len, index - 1);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    *returnSize = digitsSize + 1;
    int* result = (int*) malloc(sizeof(int) * *returnSize);
    
    // Copy into new arr
    for(int i = 0; i < digitsSize; i++){
        result[i+1] = digits[i];
    }
    result[0] = 0;
    
    // Increment from right to left
    increment(result, *returnSize, *returnSize - 1);
    
    if(result[0] == 0){
        (*returnSize)--;
        return ++result;
    }
    return result;
}