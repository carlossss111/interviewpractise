#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int data;
    Node* left;
    Node* right;
}Node;

void preOrderTraverse(Node* node, void (*visit) (Node*)){
    if(node != NULL){
        visit(node);
        preOrderTraverse(node->left, visit);
        preOrderTraverse(node->right, visit);
    }
}

void inOrderTraverse(Node* node, void (*visit) (Node*)){
    if(node != NULL){
        inOrderTraverse(node->left, visit);
        visit(node);
        inOrderTraverse(node->right, visit);
    }
}

void postOrderTraverse(Node* node, void (*visit) (Node*)){
    if(node != NULL){
        postOrderTraverse(node->left, visit);
        postOrderTraverse(node->right, visit);
        visit(node);
    }
}

Node* createTree(){
    /*
                1
            2       3
          4   5   6   7
        8
    */

    Node* root = (Node*) malloc(sizeof(Node));
    Node* n2 = (Node*) malloc(sizeof(Node));
    Node* n3 = (Node*) malloc(sizeof(Node));
    Node* n4 = (Node*) malloc(sizeof(Node));
    Node* n5 = (Node*) malloc(sizeof(Node));
    Node* n6 = (Node*) malloc(sizeof(Node));
    Node* n7 = (Node*) malloc(sizeof(Node));
    Node* n8 = (Node*) malloc(sizeof(Node));

    root->data = 1;
    n2->data = 2;
    n3->data = 3;
    n4->data = 4;
    n5->data = 5;
    n6->data = 6;
    n7->data = 7;
    n8->data = 8;

    root->left = n2;
    root->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;
    n4->left = n8;
    n4->right = NULL;
    n5->left = NULL;
    n5->right = NULL;
    n6->left = NULL;
    n6->right = NULL;
    n7->left = NULL;
    n7->right = NULL;
    n8->left = NULL;
    n8->right = NULL;

    return root;
}

void freeNode(Node* node){
    free(node);
}

void printNode(Node* node){
    printf("%d ", node->data);
}

int main(int argc, char** argv){
    Node* root = createTree();
    
    printf("Pre-order Traversal: ");
    preOrderTraverse(root, printNode);
    printf("\nIn-order Traversal: ");
    inOrderTraverse(root, printNode);
    printf("\nPost-order Traversal: ");
    postOrderTraverse(root, printNode);
    putchar('\n');

    postOrderTraverse(root, freeNode);
}