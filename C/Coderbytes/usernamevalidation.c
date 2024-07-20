/*
Codeland Username Validation
Have the function CodelandUsernameValidation(str) take the str parameter being passed and 
determine if the string is a valid username according to the following rules:

1. The username is between 4 and 25 characters.
2. It must start with a letter.
3. It can only contain letters, numbers, and the underscore character.
4. It cannot end with an underscore character.

If the username is valid then your program should return the string true, otherwise return the string false.
Examples
Input: "aa_"
Output: false
Input: "u__hello_world123"
Output: true 
*/

#include <stdio.h> 
#include <string.h>

int isletter(char c){
  return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int containsonlyvalid(char* s){
  while(*s != '\0'){
    if(!((*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z')\
    || (*s >= '0' && *s <= '9') || (*s == '_'))){
      return 0;
    }

    s++;
  }
  return 1;
}

void CodelandUsernameValidation(char * str) {
  int success = 1;

  if(strlen(str) < 4 || strlen(str) > 25)
    success = 0;
  if(!isletter(*str))
    success = 0;
  if(!containsonlyvalid(str))
    success = 0;
  if(str[strlen(str) - 1] == '_')
    success = 0;
  
  if(success)
    printf("true\n");
  else
    printf("false\n");

}

int main(void) { 
   
  // keep this function call here
  CodelandUsernameValidation(coderbyteInternalStdinFunction(stdin));
  return 0;
    
}