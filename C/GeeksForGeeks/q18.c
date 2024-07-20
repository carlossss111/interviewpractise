// gcc -g g4g/q18.c -Igeneral
#include "linkedlist.h"

//O(n) time
//O(1) space
void reverseList(IntLinkedList* list){
    //loop through each node, reverse the pointer to the node before
    //put the head at the end of the list
    IntNode* current = list->head->next;
    IntNode* prev = list->head;
    prev->next = NULL;
    while(current){
        IntNode* next = current->next;

        current->next = prev;
        prev = current;

        list->head = current;
        current = next;
    }
}

// Q18: Write a Program to reverse a linked list.
int main(int argc, char** argv){
    IntLinkedList list;
    createSampleILL(&list);
    printILL(&list);

    reverseList(&list); // absolute fucking machine

    printILL(&list);
    freeILLNodes(&list);
}