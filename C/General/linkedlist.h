#include <stdlib.h>
#include <stdio.h>

// typedef struct{
//     void* data;
//     void* next;
// }Node;

// typedef struct{
//     Node* head;
// }LinkedList;

typedef struct{
    int data;
    void* next;
}IntNode;

typedef struct{
    IntNode* head;
}IntLinkedList;

IntLinkedList* createSampleILL(IntLinkedList* list){
    IntNode* n0 = (IntNode*) malloc(sizeof(IntNode));
    IntNode* n1 = (IntNode*) malloc(sizeof(IntNode));
    IntNode* n2 = (IntNode*) malloc(sizeof(IntNode));
    IntNode* n3 = (IntNode*) malloc(sizeof(IntNode));

    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;

    n0->data = 1;
    n1->data = 2;
    n2->data = 3;
    n3->data = 4;

    list->head = n0;
    return list;
}

void printILL(IntLinkedList* list){
    IntNode* current = list->head;
    while(current){
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void freeILLNodes(IntLinkedList* list){
    IntNode* current = list->head;
    while(current){
        IntNode* next = current->next;
        free(current);
        current = next;
    }
}
