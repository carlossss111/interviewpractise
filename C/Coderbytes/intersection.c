#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

int createIntArr(int* arr, char* str, const char* delimiter){
  char* token = strtok(str, delimiter);
  int i = 0;
  while(token != NULL){
    arr[i] = strtol(token, NULL, 10);
    token = strtok(NULL, delimiter);
    i++;
  }
  return i;
}

void printarr(int* arr, int size){
  for(int i = 0; i < size; i++){
    printf("%d,", arr[i]);
  }
  putchar('\n');
}

void FindIntersection(char * strArr[], int arrLength) {
  char* strA = strArr[0];
  char* strB = strArr[1];

  int arrA[512];
  int arrB[512];
  int sizeA = createIntArr(arrA, strA, ",");
  int sizeB = createIntArr(arrB, strB, ",");


  printarr(arrA, sizeA);
  printarr(arrB, sizeB);

  printf("%s", strArr[0]);
}


int main(void) { 
   
  // keep this function call here
  char t[] = "1, 2";
  char h[] = "4, 5, 1";
  char *A[] = {t,h};
  //char * A[] = coderbyteInternalStdinFunction(stdin);
  //int arrLength = sizeof(A) / sizeof(*A);
  FindIntersection(A, 2);
  return 0;
    
}