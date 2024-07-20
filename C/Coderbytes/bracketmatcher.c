/*
Bracket Matcher
Have the function BracketMatcher(str) take the str parameter being passed and return 1 
if the brackets are correctly matched and each one is accounted for. Otherwise return 0. 
For example: if str is "(hello (world))", then the output should be 1, but if str is "((hello (world))" 
the the output should be 0 because the brackets do not correctly match up. Only "(" and ")" 
will be used as brackets. If str contains no brackets return 1.
Examples
Input: "(coder)(byte))"
Output: 0
Input: "(c(oder)) b(yte)"
Output: 1 
*/

#include <stdio.h> 
#include <string.h>

typedef struct{
  char data[512];
  int top;
}Stack;

void push_stack(Stack* stk, char data){
  stk->data[stk->top] = data;
  stk->top++;
}

char pop_stack(Stack* stk) {
  if(stk->top == 0){
    return EOF;
  }

  char data = stk->data[stk->top];
  stk->top--;
  return data;
}

void BracketMatcher(char * str) {
  Stack stk;
  stk.top = 0;
  int success = 1;

  while(*str != '\0'){
    if(*str == '('){
      push_stack(&stk, '(');
    }
    else if(*str == ')') {
      char c = pop_stack(&stk);
      if(c == EOF){
        success = 0;
        break;
      }
    }

    str++;
  }

  if(stk.top != 0){
    success = 0;
  }
  
  // code goes here  
  printf("%d\n", success);

}

int main(void) { 
   
  // keep this function call here
  BracketMatcher(coderbyteInternalStdinFunction(stdin));
  return 0;
    
}