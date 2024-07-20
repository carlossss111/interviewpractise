#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> // gcc -lm
#include <stdbool.h>

//first num is 2^0, then 2^1, 2^2, etc.
// return (int) strtol(num, NULL, 2);
int bintoint(char* bin, bool issigned) {
    int power = 0;
    int result = 0;

    for(int i = strlen(bin)-1; i >= 0; i--){
        if(issigned && i == 0 && strlen(bin) == 8 && bin[i] == '1') {
            result *= -1; //signedness
        }
        else if(bin[i] == '1') {
            result += pow(2, power);
        }


        power++;
    }
    return result;
}

// 
void inttobin(char* buff, int num, bool issigned) {
    for(int i = 0; i < 8; i++){
        buff[i] = '0';
    }
    buff[9] = '\0';


    int i = strlen(buff) - 1;

    if(issigned && num < 0){ // flip and add the last bit
        num = -num;
        num += 128;
    }

    // add the mod of 2 then divide by 2
    while (num > 0) { 
        buff[i] = (char) (num % 2) + '0'; 
        num = num / 2; 
        i--; 
    } 
}

// Q10: Write a Program to Convert Binary to Decimal.
int main(int argc, char** argv){
    char bin[9];

    printf("Enter a binary number: ");
    if(fgets(bin, sizeof(bin), stdin) == NULL) {
        fprintf(stderr, "Failed to read input!");
        return 1;
    }
    for(int i = 0; i < sizeof(bin); i++){
        if (bin[i] == '\n'){
            bin[i] = '\0';
            break;
        }
    }

    bool issigned = true;
    int num = bintoint(bin, issigned);
    char buff[9]; inttobin(buff, num, issigned);

    printf("%d\n", num);
    printf("%s\n", buff);

    return 0;
}