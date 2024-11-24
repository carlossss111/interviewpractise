#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>


typedef struct {
    unsigned long int field;
    int size;
} Bitset;


Bitset* bitsetCreate(int size) {
    Bitset* bitset = (Bitset*) malloc(sizeof(Bitset));
    bitset->field = 0;
    bitset->size = size;
    return bitset;
}

void bitsetFix(Bitset* obj, int idx) {
    int rdx = obj->size - 1 - idx;
    obj->field |= (1 << rdx);
}

void bitsetUnfix(Bitset* obj, int idx) {
    int rdx = obj->size - 1 - idx;
    obj->field &= ~(1 << rdx);
}

void bitsetFlip(Bitset* obj) {
    obj->field = ~obj->field;
}

int bitsetCount(Bitset* obj) {
    int count = 0;
    for(int i = 0; i < obj->size; i++){
       if(obj->field & (1 << i)){
           count++;
       }
    }
    return count;
}

bool bitsetAll(Bitset* obj) {
    int count = bitsetCount(obj);
    return count == obj->size;
}

bool bitsetOne(Bitset* obj) {
    return obj->field > 0;
}


char* bitsetToString(Bitset* obj) {
    char* bitstr = (char*) malloc(sizeof(char) * (obj->size + 1));
    char* start = bitstr;
    int rdx = obj->size - 1;
    while(rdx >= 0){
        if (obj->field & (1 << rdx)){
            *bitstr = '1';
        }
        else{
            *bitstr = '0';
        }
        bitstr++;
        rdx--;
    }
    *bitstr = '\0';
    return start;
}

void bitsetFree(Bitset* obj) {
    free(obj);
}

