/*
First Factorial
Have the function FirstFactorial(num) take the num parameter being passed and return 
the factorial of it. For example: if num = 4, then your program should return (4 * 3 * 2 * 1) = 24. 
For the test cases, the range will be between 1 and 18 and the input will always be an integer.
Examples
Input: 4
Output: 24
Input: 8
Output: 40320 
*/

#include <stdio.h> 
#include <string.h>

void FirstFactorial(int num) {
  int fac = 1;

  // Iterative method
  for(int i = num; i > 0; i--){
    fac *= i;
  }
  
  // code goes here  
  printf("%d", fac);

}

int main(void) { 
   
  // keep this function call here
  FirstFactorial(coderbyteInternalStdinFunction(stdin));
  return 0;
    
}