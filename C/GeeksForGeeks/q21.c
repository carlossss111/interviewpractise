#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//O(n/2) time
//O(1) space
int ispalidrome(char* str){
    char* leftptr = str;
    char* rightptr = &str[strlen(str) - 1];

    // move both pointers toward the centre until they meet
    // if they meet, great, but if there are not equal at any point then fail
    while(leftptr != rightptr){
        if(*leftptr != *rightptr)
            return 0;

        leftptr++;
        if(leftptr == rightptr) // for odd lengths
            break;
        rightptr--;
    }

    return 1;
}

//Q21: Write a Program to check if the given string is a palindrome string or not.
int main(int argc, char** argv){
    if(argc != 2){
        return 1;
    }

    if(ispalidrome(argv[1])){
        printf("Is a palidrome!\n");
    }
    else{
        printf("Is not a palindrome!\n");
    }

    return 0;
}