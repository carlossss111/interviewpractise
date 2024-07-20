#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(1) // without this, mystruct would be size 8. with this it is size 5

typedef struct{
    int mynum;      // 4 byte
    char mychar;    // 1 byte
}mystruct;

typedef struct{
    int mynum;      // 4 byte
    char* myptr;    // 8 byte address (the char memory is not within the struct!)
    char mystr[4];  // 4 byte stack
}mypointedstruct;

int main(int argc, char** argv) {
    mystruct onstack;
    printf("%d\n", sizeof(mystruct));

    mypointedstruct onstackagain;
    char newstr[] = "HELLO WORLD GOODBYE UNIVERSE";
    onstackagain.myptr = newstr;
    printf("%d\n", sizeof(mypointedstruct));
    printf("%s %d\n", onstackagain.myptr, (strlen(onstackagain.myptr) + 1) * sizeof(char));

    mystruct* onheap;
    onheap = (mystruct*) malloc(sizeof(mystruct));
    printf("%d %d\n", sizeof(onheap), sizeof(*onheap));
    free(onheap);
    return 0;
}