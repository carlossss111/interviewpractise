#include <stdio.h>

int hammingWeight(int n) {
    int weight = 0;
    for (int i = 0; i < 32; i++){
        if (n & (1 << i)){
            weight++;
        }
    }

    return weight;
}

int main(int argc, char** argv){
    printf("Expected: 30\nActual: %d\n", hammingWeight(2147483645));
    return 0;
}

