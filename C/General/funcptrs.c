#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int aplusb(int a, int b){
    return a + b;
}

int aminusb(int a, int b){
    return a - b;
}

int fun(int a, int b, int (*funcptr)(int, int)){
    a++; b++;
    return (*funcptr)(a, b);
}

int main(int argc, char** argv){
    int (*myptr)(int, int) = &aplusb;
    printf("%d\n", fun(2,2,myptr));
}
