#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strtokmethod(char* inputstr, const char* delimiter){
    char* token;

    token = strtok(inputstr, delimiter);
    while(token != NULL){
        printf("%c ", *token);
        token = strtok(NULL, delimiter);
    }
    putchar('\n');
}

void rawmethod(char* inputstr, const char* delimiter){
    char* prev = inputstr;
    char* curr = inputstr + 1;

    putchar(*prev);
    putchar(' ');
    while(*curr != '\0'){
        if(*prev == ' '){
            putchar(*curr);
            putchar(' ');
        }

        prev++;
        curr++;
    }
    putchar('\n');
}

// Q22: Write a program to print the first letter of each word.
int main(int argc, char** argv) {
    char* inputstr = argv[1];

    //strtokmethod(inputstr, " ");
    rawmethod(inputstr, " ");

    return 0;
}