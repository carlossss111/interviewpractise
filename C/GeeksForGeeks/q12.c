#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// shoutout graham
// UNWIND THE FUCKING STACK BOYS
int nat(int num){
    if(num == 0){
        return 0;
    }
    return nat(num-1) + num;
}

// Q12: Write a Program to Calculate the Sum of Natural Numbers using recursion.
int main(int argc, char** argv) {
    char buff[36]; int num;
    if(fgets(buff, sizeof(buff), stdin) == NULL){
        fprintf(stderr, "err etc\n");
        return 1;
    }
    num = strtol(buff, NULL, 10);

    printf("%d\n", nat(num));
    return 0;
}