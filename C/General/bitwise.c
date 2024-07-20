#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void putbin(unsigned short num) {
    unsigned int maxPow = 1 << (sizeof(num) * 8 - 1);
    for(int i = 0; i < sizeof(num) * 8; ++i) {
        printf("%u", num & maxPow ? 1 : 0);
        num = num<<1;
        if(i == 7){
            putchar(' ');
        }
    }
    putchar('\n');
}

int main(int argc, char** argv){
    unsigned short num = 0;
    putbin(num);

    // set 4th bit
    num |= 1 << 3;
    putbin(num);

    // unset 4th bit
    num &= ~(1 << 3);
    putbin(num);
    num &= 0 << 3;
    putbin(num);

    // flip all bits
    num = ~num;
    putbin(num);
}
