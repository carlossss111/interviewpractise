#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){
    char mystr[] = "carrot, potato broccoli mustard mayonaise";
    char delimiter[] = " ";
    char* token;

    // This will point to the START of the string, e.g. 'c'.
    token = strtok(mystr, delimiter);

    while(token != NULL) {
        printf("%s, ", token);
        // This will point to the NEXT delimiter, e.g. right before 'p'
        token = strtok(NULL, delimiter);
    }
    putchar('\n');

    return 0;
}