#include <stdio.h>
#include <stdlib.h>
// No <string.h> allowed! (or I could just use strcat).

int mystrlen(const char* ptr){
    int size = 0;
    while(*ptr != '\0'){
        size++;
        ptr++;
    }
    return size;
}

void mystrcpy(char* dest, const char* src){
    while(*src != '\0'){
        *dest = *src;
        src++;
        dest++;
    }
    *(dest++) = '\0';
}

int mystrcat(char* dest, const char* src){
    // get to end of string
    while(*dest != '\0'){
        dest++;
    }

    while(*src != '\0'){
        *dest = *src;
        dest++;
        src++;
    }

    *(dest++) = '\0';
}

void myputs(const char* str){
    while(*str != '\0'){
        putchar(*str);
        str++;
    }
    putchar('\n');
}

//Q20: Write a Program to concatenate two strings.
int main(int argc, char** argv){
    if(argc != 3)
        return 1;

    char strA[255];
    mystrcpy(strA, argv[1]);
    const char* strB = argv[2];

    mystrcat(strA, strB);
    
    myputs(strA);
}