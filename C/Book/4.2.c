#include <stdio.h>
#include <stdlib.h>
//#include <math.h>

// UTILITY 

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

void postOrderTraverse(Node* node, void (*visit) (Node*)){
    if(node != NULL){
        postOrderTraverse(node->left, visit);
        postOrderTraverse(node->right, visit);
        visit(node);
    }
}

void freeNode(Node* node){
    free(node);
}

void printNode(Node* node){
    printf("%d ", node->data);
}

// PROBLEM

/*

Node* recurseMST(Node* node, int* arr, int index, int leftBound, int rightBound){
    node->data = arr[index];

    int nextLeftIndex = index / 2;
    int nextRightIndex = index + (index - nextLeftIndex);
    
    if(nextLeftIndex != nextRightIndex){
        // create left node
        node->left = (Node*) malloc(sizeof(Node));
        node->left = recurseMST(node->left, arr, nextLeftIndex, leftBound, nextLeftIndex);
    }
    else{
        node->left = NULL;
    }
    
    if(nextLeftIndex != nextRightIndex){
        // create right node
        node->right = (Node*) malloc(sizeof(Node));
        node->right = recurseMST(node->right, arr, nextRightIndex, nextRightIndex, rightBound);
    }
    else{
        node->right = NULL;
    }
    return node;
}

Node* minimumSizeTree(int* arr, int arrSize){
    int height = (int) ceil(log2(arrSize));
    Node* root = (Node*) malloc(sizeof(Node));
    recurseMST(root, arr, height, 0, arrSize - 1);
    return root;
}

*/

Node* createMinimalBST(int arr[], int start, int end) {
    if(end < start){
        return NULL;
    }

    int mid = (start + end) / 2;
    Node* n = (Node*) malloc(sizeof(Node));
    n->data = arr[mid];
    n->left = createMinimalBST(arr, start, mid - 1);
    n->right = createMinimalBST(arr, mid + 1, end);
    return n;
}

Node* minimumSizeTree(int array[], int length){
    return createMinimalBST(array, 0, length - 1);
}

int main(int argc, char** argv) {
    int inputArr[] = {0,1,2,3,4};

    Node* root = minimumSizeTree(inputArr, sizeof(inputArr)/sizeof(int));
    postOrderTraverse(root, printNode);
    postOrderTraverse(root, freeNode);
}