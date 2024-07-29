#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char stack[10000];
char* stack_ptr = stack;

void push_stack(char c){
    stack_ptr++;
    *stack_ptr = c;
}

char pop_stack(){
    char c = *stack_ptr;
    stack_ptr--;
    return c;
}

bool isValid(char* s) {
    push_stack(EOF);
    
    while(*s != '\0'){
        if(*s == '(' || *s == '[' || *s == '{'){
            push_stack(*s);
        }
        
        if(*s == ')'){
            if(pop_stack() != '('){
                return false;
            }
        }
        if(*s == ']'){
            if(pop_stack() != '['){
                return false;
            }
        }
        if(*s == '}'){
            if(pop_stack() != '{'){
                return false;
            }
        }
        
        s++;
    }
    
    if(pop_stack() != EOF){
        return false;
    }
    
    return true;
}