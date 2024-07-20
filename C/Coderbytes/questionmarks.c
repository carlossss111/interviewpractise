/*
Questions Marks
Have the function QuestionsMarks(str) take the str string parameter, which will contain single digit numbers, 
letters, and question marks, and check if there are exactly 3 question marks between every pair of two numbers 
that add up to 10. If so, then your program should return the string true, otherwise it should return the string 
false. If there aren't any two numbers that add up to 10 in the string, then your program should return false as 
well.

For example: if str is "arrb6???4xxbl5???eee5" then your program should return true because there are 
exactly 3 question marks between 6 and 4, and 3 question marks between 5 and 5 at the end of the string.
Examples
Input: "aa6?9"
Output: false
Input: "acc?7??sss?3rr1??????5"
Output: true 
*/


#include <stdio.h> 
#include <string.h>

int isnumber(char c){
  if(c >= '0' && c <= '9'){
    return 1;
  }
  return 0;
}

int tonumber(char c){
  return c - '0';
}

void QuestionsMarks(char * str) {
  int num = 0;
  int numofquestionmarks = 0;
  int success = 0;

  while(*str != '\0'){
    if(isnumber(*str)){
      if (num + tonumber(*str) == 10) {
        success = 1;
        if(numofquestionmarks != 3){
          success = 0;
          break;
        }
      }
      numofquestionmarks = 0;
      num = tonumber(*str);
    }

    if(*str == '?'){
      numofquestionmarks++;
    }

    str++;
  }


  if(success){
    printf("true\n");
  }
  else{
    printf("false\n");
  }
}

int main(void) { 
   
  // keep this function call here
  QuestionsMarks(coderbyteInternalStdinFunction(stdin));
  return 0;
    
}