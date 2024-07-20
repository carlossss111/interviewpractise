#include <stdio.h> 
#include <string.h>

// you could also use a buffer like in the official solutions but thats not memory safe imo

int isletter(char a){
  if((a >= 'A' && a < 'Z') || (a >= 'a' && a <= 'z')){
    return 1;
  }
  return 0;
}

void LongestWord(char * sen) {
    char* current = sen+1;
    char* prev = sen;
    char* wordstart = sen;
    int length = 1;
    int longestlength = 0;
    char* longestword = sen;

    while(*current != '\0'){
        // At the start of a word, we want to set a pointer
        if(!isletter(*prev) && isletter(*current)){
            wordstart = current;
            length = 0;
        }

        // at the end of a word, we want to check if this is the longest word
        if(!isletter(*current)){
            if(length > longestlength){
                longestlength = length;
                longestword = wordstart;
            }
        }

        if(isletter(*current)){
            length++;
        }
        prev++;
        current++;
    }
    if(length > longestlength){
        longestlength = length;
        longestword = wordstart;
    }

    printf("%.*s\n", longestlength, longestword);
}

int main(void) { 
   
  // keep this function call here
  LongestWord("fun&!! time"); //should print 'time'
    
}