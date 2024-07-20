#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 4

void printmat(int mat[][N], int rows, int cols){
    for(int i = 0; i < cols; i++){
        for(int j = 0; j < rows; j++){
            printf("%d", mat[i][j]);
        }
        putchar('\n');
    }
}

// i cant be assed for this one
// tldr B[i][j] = A[j][i]; 

// Q19: Write a Program to find the Transpose of a Matrix.
int main(int argc, char** argv){
    int mat[N][N] = {{1, 1, 1, 1},
                     {2, 2, 2, 2},
                     {3, 3, 3, 3},
                     {4, 4, 4, 4}};

    printmat(mat, N, N);

    return 0;
}
