#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reversenaive(char* buffin, char* buffout){
    int j = strlen(buffin)-1;
    for(int i = 0; i < strlen(buffin); i++) {
        buffout[i] = buffin[j];
        j--;
    }
}

void reverseinplace(char* buff){
    char* leftptr = buff;
    char* rightptr = &buff[strlen(buff)-1];
    char temp;

    while(leftptr != rightptr){
        // This is the important part
        temp = *leftptr;
        *leftptr = *rightptr;
        *rightptr = temp;

        leftptr++;
        // odd lengths
        if(leftptr == rightptr){
            break;
        }
        rightptr--;
    }
}

// Q14: Write a Program to Reverse an Array. (Classic!)
// let argv[1] be the array to be reversed as a char*
int main(int argc, char** argv){
    // let argv[1] be the array to be reversed as a char*

    char naive[255]; char naiveout[255];
    char inplace[255];
    strncpy(naive, argv[1], 255);
    strncpy(inplace, argv[1], 255);

    reversenaive(naive, naiveout);
    reverseinplace(inplace);
    printf("%s\n", naiveout);
    printf("%s\n", inplace);

    return 0;
}