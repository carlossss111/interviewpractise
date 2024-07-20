#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printpascal(int numofrows){

}

// Q25: Write a program to print Pascal’s triangle pattern.
int main(int argc, char** argv){
    int numofrows = strtol(argv[1], NULL, 10);
    printpascal(numofrows);
    return 0;
}