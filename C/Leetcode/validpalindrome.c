/*
 * A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.



Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.



Constraints:

    1 <= s.length <= 2 * 105
    s consists only of printable ASCII characters.
*/

// Very easy conceptually, but with C became a good reminder on ASCII encodings

#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

bool isPalindrome(char* s) {
    char* left_ptr = s;
    char* right_ptr = &s[strlen(s) - 1];

    while(left_ptr <= right_ptr && *left_ptr != '\0'){
        // Skip non-alphanumerics
        if (!((*left_ptr >= '0' && *left_ptr <= '9') || (*left_ptr >= 'A' && *left_ptr <= 'Z') || (*left_ptr >= 'a' && *left_ptr <= 'z'))) {
            left_ptr++;
            continue;
        }
        if (!((*right_ptr >= '0' && *right_ptr <= '9') || (*right_ptr >= 'A' && *right_ptr <= 'Z') || (*right_ptr >= 'a' && *right_ptr <= 'z'))) {
            right_ptr--;
            continue;
        }

        // Make uppercase
        char left = *left_ptr;
        char right = *right_ptr;
        if (*left_ptr < 'a') {
            left = *left_ptr + ('a' - 'A');
        }
        if (*right_ptr < 'a') {
            right = *right_ptr + ('a' - 'A');
        }

        // Actual palindrome check 
        if (left != right) {
            return false;
        }

        // Traversal
        left_ptr++;
        right_ptr--;
    }
    return true;
}

int main(int argc, char** argv) {
    bool ans;

    ans = isPalindrome((char*) "Race a car");
    assert(ans == false);
    printf("%d\n", ans);

    ans = isPalindrome((char*) "Race/car");
    assert(ans == true);
    printf("%d\n", ans);
    return 0;
}
