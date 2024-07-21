#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){
    int a = 5;
    char* b = "hello";
    float c = 5.f;

    void* voidptr;

    voidptr = &a;
    printf("%d\n", *((int*) voidptr));

    voidptr = b;
    printf("%s\n", (char*) voidptr);

    voidptr = &c;
    printf("%f\n", *((float*) voidptr));

    printf("%d\n", sizeof(voidptr));
    //printf("%d\n", sizeof(*voidptr)); // Invalid without type!

    return 0;
}