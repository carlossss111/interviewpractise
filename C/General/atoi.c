#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int my_atoi(char* str){
    int num = 0;
    int power = 0;
    int i = strlen(str) - 1;

    for(; i >= 0; i--){
        int digit = str[i] - '0';
        num += digit * pow(10, power);
        power++;
    }
}

char* my_itoa(int num, char* buff){
    // count num of digits
    int numdigits = 1;
    int temp = num;
    while(temp > 9){
        temp /= 10;
        numdigits++;
    }

    // do thing
    int i = numdigits - 1;
    while(num > 0){
        buff[i] = (num % 10) + '0';
        num /= 10;
        i--;
    }
    return buff;
}

int main(int argc, char** argv){
    printf("%d\n", my_atoi("101243"));
    char buff[10];
    my_itoa(101243, buff);
    printf("%s\n", buff);
    return 0;
}
