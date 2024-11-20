#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* addBinary(char* a, char* b) {
    char* answer = (char*) malloc(sizeof(char) * 10001);
    answer[10000] = '\0';
    
    int carry = 0;
    
    int a_len = strlen(a);
    int b_len = strlen(b);
    
    int a_ind = strlen(a) - 1;
    int b_ind = strlen(b) - 1;
    int answer_ind = 9999;
    
    char a_c = a[a_ind];
    char b_c = b[b_ind];
    int finished = 0;
    
    while(!finished){
        if(a_ind == 0 && b_ind == 0){
            finished = 1;
        }
        // Add digit 
        if (a_c == '1' && b_c == '1'){
            if (carry){
                answer[answer_ind] = '1';
                carry = 1;
            }
            else{
                answer[answer_ind] = '0';
                carry = 1;
            }
        }
        else if (a_c == '0' && b_c == '1'){
            if (carry){
                answer[answer_ind] = '0';
                carry = 1;
            }
            else{
                answer[answer_ind] = '1';
                carry = 0;
            }
        }
        else if (a_c == '1' && b_c == '0'){
            if (carry) {
                answer[answer_ind] = '0';
                carry = 1;
            }
            else {
                answer[answer_ind] = '1';
                carry = 0;
            }
        }
        else {
            if (carry) {
                answer[answer_ind] = '1';
                carry = 0;
            }
            else {
                answer[answer_ind] = '0';
                carry = 0;
            }
        }
         
        if (a_ind != 0){
            a_ind--;
            a_c = a[a_ind];
        } else {
            a_c = '0';
        }
        if (b_ind != 0){
            b_ind--;
            b_c = b[b_ind];
        } else {
            b_c = '0';
        }

        
        answer_ind--;
    }

    if(carry){
        answer[answer_ind] = '1';
    }
    else{
        answer_ind++;
    }
    
    return &(answer[answer_ind]);
}

int main(int argc, char** argv){
    printf("%s\n",addBinary("11", "0"));
    return 0;
}