#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fibbonacci is the last two numbers in the sequence added together
// n = n[-1] + n[-2]
// base case = 0, 1
int fibb(int n){ 
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    return fibb(n - 1) + fibb(n - 2);
}

//Q11: Write a Program to print the Fibonacci series using recursion.
int main(int argc, char** argv) {
    // Take Input
    char buff[32];
    int target;
    if(fgets(buff, sizeof(buff), stdin) == NULL){
        fprintf(stderr, "Failed to read!\n");
        return 1;
    }
    target = strtol(buff, NULL, 10);

    // Do fibb
    for(int i = 0; i < target; i++){
        printf("%d ", fibb(i));
    }
    putchar('\n');
}