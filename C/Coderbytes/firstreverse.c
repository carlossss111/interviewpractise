/*
Have the function FirstReverse(str) take the str parameter being passed and return the string 
in reversed order. For example: if the input string is "Hello World and Coders" then your program 
should return the string sredoC dna dlroW olleH. 
*/

#include <stdio.h> 
#include <string.h>

void swap(char* a, char* b){
  char temp = *b;
  *b = *a;
  *a = temp;
}

// Thankyou coderbytes for passing in CONST strings without any indication!
void FirstReverse(char * str) {
  char runtimestr[255];
  strcpy(runtimestr, str);
  char* left = runtimestr;
  char* right = &runtimestr[strlen(runtimestr) - 1];

  while(left != right){
    swap(left, right);

    left++;
    if(left == right)
      break;
    right--;
  }

  // code goes here  
  printf("%s", runtimestr);

}

int main(void) { 
  // keep this function call here
  FirstReverse(coderbyteInternalStdinFunction(stdin));
  return 0;
    
}