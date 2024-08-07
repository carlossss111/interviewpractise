/*
7. Reverse Integer
Medium

Given a signed 32-bit integer x, return x with its digits reversed. 
If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Example 1:
Input: x = 123
Output: 321

Example 2:
Input: x = -123
Output: -321

Example 3:
Input: x = 120
Output: 21

Constraints:
-231 <= x <= 231 - 1
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define INT_MAX     2147483647
#define INT_MAX_ARR {2,1,4,7,4,8,3,6,4,7}

int reverse(int num){
    // Get number of digits
    int copynum = num;
    int len = 0;
    while(copynum != 0){
        copynum /= 10;
        len++;
    }
    
    // Reverse
    int max[] = INT_MAX_ARR;
    bool safe = false;
    int power = len;
    int rev = 0;
    int mi = 0;
    while(power != 0){
        int digit = num % 10;
        
        // Bounds check
        if(!safe){
            if(len != 10){
                safe = true;
            }
            else if(max[mi] < abs(digit)){
                return 0;
            }
            else if (max[mi] > abs(digit)){
                safe = true;
            }
        }
        
        rev += digit * pow(10,--power);
        num /= 10;
        mi++;
    }
    
    return rev;
}

int main(int argc, char** argv){
    printf("%d\n", reverse(123));
    return 0;
}