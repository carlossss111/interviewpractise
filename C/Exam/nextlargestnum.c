/*
Given an int, print the next largest number with the digits in the input.
e.g.
123 -> 132
14351 -> 14513
100100 -> 101000

If a number does not have a next largest with the given digits, print -1.
999 -> -1
*/

/*
The naive approach would be to try every combination and pick the smallest.

A better approach would be to follow this psuedocode:
from right:
    continue until digit L < digit R
    swap L and R
    break

from right until reaching point at first swap:
    if digit L > digit R
    swap L and R

O(n) time O(1) space
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define chartoint(n) n - '0'

void numtostr(int num, char* buff){
    // count num of digits
    int numdigits = 1;
    int temp = num;
    while(temp > 9){
        temp /= 10;
        numdigits++;
    }

    // do thing
    int i = numdigits - 1;
    while(num > 0){
        buff[i] = (num % 10) + '0';
        num /= 10;
        i--;
    }
}

void swap(char* a, char* b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

void solution(int inputnum){
    char str[30];
    for(int i = 0; i < 30; i++){
        str[i] = '\0';
    }
    numtostr(inputnum, str);
    int stopindex = 0;

    for(int lindex = strlen(str)-2; lindex >= 0; lindex--){
        int rindex = lindex+1;
        if(chartoint(str[lindex]) < chartoint(str[rindex])){
            swap(&str[lindex], &str[rindex]);
            stopindex = lindex;
            break;
        }

    }

    for(int lindex = strlen(str)-2; lindex > stopindex; lindex--){
        int rindex = lindex+1;
        if(chartoint(str[lindex]) > chartoint(str[rindex])){
            swap(&str[lindex], &str[rindex]);
        }
    }

    printf("%s\n", str);
}

int main(int argc, char** argv){
    solution(strtol(argv[1], NULL, 10));
    return 0;
}

// Passed the visible test cases
// Took 35 minutes
