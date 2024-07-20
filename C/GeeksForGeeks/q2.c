#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Q2: Write a Program to find the Sum of two numbers entered by the user.
// I wanted to do this properly with memory safety, e.g. not with scanf.
int main(int argc, char** argv){
    char buff[255];
    printf("Enter two numbers A and B: ");
    if (fgets(buff, sizeof(buff), stdin) == NULL){
        fprintf(stderr, "Error reading input!\n");
        return 1;
    }

    char* spacePtr = strtok(buff, " ");
    spacePtr = strtok(NULL," ");
    if (spacePtr == NULL) {
        fprintf(stderr, "Error reading delimiter!\n");
        return 1;
    }

    printf("%ld\n", strtol(buff, NULL, 10) + strtol(spacePtr++, NULL, 10));

}