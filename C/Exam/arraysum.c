/*
Given an array of strings where the part before the colon is a key string, and the part after is an value integer,
add the values of each key.
Print the elements alphabetically.
Do not print elements that have value = 0.

e.g.
I = {"X:1", "B:4", "Y:2", "B:-2", "Y:-2"}
O = "B:2, X:1"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char key;
    int val;
}Map;

void getstr(char* str, char* buff){
    while(*str != '\0'){
        if(*str == ':')
            break;
        *buff = *str;
        buff++;
        str++;
    }
}

int getnum(char* str){
    while(*str != '\0'){
        if(*str == ':')
            break;
        str++;
    }
    str++;
    return strtol(str, NULL, 10);
}

void printmaplist(Map* maplist, int listlen){
    for(int i = 0; i < listlen; i++){
        if(maplist[i].val != 0){
            printf("%c:%d ", maplist[i].key, maplist[i].val);
        }
    }
    putchar('\n');
}

void shiftallup(Map* maplist, int listlen, int start){
    for(int i = listlen - 1; i >= start; i--){
        maplist[i+1] = maplist[i];
    }
}

void insert(Map* maplist, int listlen, char key, char val){
    for(int i = 0; i < listlen; i++){
        if(maplist[i].key > key){
            shiftallup(maplist, listlen, i);
            maplist[i].key = key;
            maplist[i].val = val;
            return;
        }
    }

    maplist[listlen].key = key;
    maplist[listlen].val = val;
}

Map* getmap(Map* maplist, int listlen, char key){
    for(int i = 0; i < listlen; i++){
        if(maplist[i].key == key){
            return &maplist[i];
        }
    }
    return NULL;
}

void solution(char* arrStr[], int arrLength){
    Map* maplist = (Map*) malloc(sizeof(Map) * arrLength);
    int listlen = 0;
    
    for(int i = 0; i < arrLength; i++){
        char key[10];
        getstr(arrStr[i], key);
        int val = getnum(arrStr[i]);
        Map* current = getmap(maplist, listlen, key[0]);
        if(current == NULL){
            // maplist[i].key = key[0];
            // maplist[i].val = val;
            insert(maplist, listlen, key[0], val);
            listlen++;
        }
        else{
            current->val += val;
        }
    }

    printmaplist(maplist, listlen);
    free(maplist);
}

int main(int argc, char** argv){
    char* arrStr[] = {"X:1", "B:4", "Y:2", "B:-2", "Y:-2"};
    solution(arrStr, 5);
    return 0;
}

// Passed the visibile test cases
// Took 1hr 30 because I massively panicked. I tried to do an insertion sort and then a bubble sort and it didnt work.
// only after sorting AS i was inserting did it work after I calmed down.
// Need more practise on sorting
