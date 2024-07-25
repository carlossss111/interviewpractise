/*
9. Palindrome Number
Given an integer x, return true if x is a palindrome, and false otherwise.

Example 1:
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Example 2:
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

Constraints:
-231 <= x <= 231 - 1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void itoa(char* buff, int num){
    for(int i = 0; i < 20; i++){
        buff[i] = '\0';
    }
    
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
}

int isPalindrome(int x) {
    if(x < 0)
        return 0;
    
    char str[20];
    itoa(str, x);
    
    int left = 0;
    int right = strlen(str) - 1;
    
    while(left <= right){
        if(str[left] != str[right]){
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}