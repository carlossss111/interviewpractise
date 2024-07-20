/*
Find Intersection
Have the function FindIntersection(strArr) read the array of strings stored in 
strArr which will contain 2 elements: the first element will represent a list of 
comma-separated numbers sorted in ascending order, the second element will represent 
a second list of comma-separated numbers (also sorted). Your goal is to return a 
comma-separated string containing the numbers that occur in elements of strArr in 
sorted order. If there is no intersection, return the string false.
Examples
Input: {"1, 3, 4, 7, 13", "1, 2, 4, 13, 15"}
Output: 1,4,13
Input: {"1, 3, 9, 10, 17, 18", "1, 4, 9, 10"}
Output: 1,9,10 
*/

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

// how the heck does coderbytes not support strtok() COME ON >:(
/*
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
*/

int createIntArr(int* arr, char* str, const char* delimiter){
  char num[8];
  char* numptr = num; 
  char* numstart = num;
  for(int n = 0; n < 8; n++){
    numstart[n] = '\0';
  }
  int index = 0;
  while(*str != '\0'){

    if(*str >= '0' && *str <= '9'){
      *numptr = *str;
      numptr++;
    }

    if(*str == ','){
      arr[index] = strtol(numstart, NULL, 10);
      index++;
      for(int n = 0; n < 8; n++){
        numstart[n] = '\0';
      }
      numptr = numstart;
    }

    str++;
  }
  arr[index] = strtol(numstart, NULL, 10);
  index++;

  return index;
}

void printarr(int* arr, int size){
  for(int i = 0; i < size; i++){
    printf("%d", arr[i]);
    if(i != size - 1){
      printf(",");
    }
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

  int resultArr[512];
  int resultSize = 0;
  int* ptrR = resultArr;
  int* ptrA = arrA;
  int* ptrB = arrB;
  while(*ptrA != '\0' && *ptrB != '\0'){
    if(*ptrA == *ptrB){
      resultSize++;
      *ptrR = *ptrA;
      ptrR++;
      ptrA++;
    }

    if(*ptrA > *ptrB){
      ptrB++;
    }

    if(*ptrB > *ptrA){
      ptrA++;
    }
  }

  if(resultSize > 0)
    printarr(resultArr, resultSize);
  else
    printf("false\n");
}

int main(void) { 
   
  // keep this function call here
  char * A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  FindIntersection(A, arrLength);
  return 0;
    
}