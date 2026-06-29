/*
 * Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.



Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"

Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.



Constraints:

    1 <= s.length <= 104
    s contains English letters (upper-case and lower-case), digits, and spaces ' '.
    There is at least one word in s.



Follow-up: If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?
 */

// O(1) memory, O(n) time (probably sort of)

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void swap_char(char* ptr_a, char* ptr_b) {
    char temp = *ptr_b;
    *ptr_b = *ptr_a;
    *ptr_a = temp;
}

void swap_word(char* str, int length) {
    char* l_ptr = str;
    char* r_ptr = &str[length];

    while (l_ptr <= r_ptr) {
        swap_char(l_ptr, r_ptr);
        l_ptr++;
        r_ptr--;
    }
}

int wordlen(char* str) {
    char* p = str;
    int len = 0;
    while (*p == ' ') {
        len++;
        p++;
    }

    while (*p != '\0' && *p != ' ') {
        len++;
        p++;
    }
    return len;
}

char* reverseWords(char* s) {
    int len = strlen(s);

    // Swap every character including whitespace
    char* l_ptr = s;
    char* r_ptr = &s[len - 1];

    while (l_ptr <= r_ptr) {
        swap_char(l_ptr, r_ptr);
        l_ptr++;
        r_ptr--;
    }

    // Swap each word including whitespace (bit fucky)
    char* ptr = s;
    while (*ptr != '\0') {
        if (ptr != s && *(ptr-1) != ' '){
            ptr++;
            continue;
        }

        int word_len = wordlen(ptr);
        swap_word(ptr, word_len-1);

        ptr++;
    }

    // Cut final bit of whitespace
    char* end_ptr = &s[len - 1];
    int whitespace_count = 0;
    while(end_ptr > s && *end_ptr == ' ') {
        whitespace_count++;
        end_ptr--;
    }
    *(end_ptr+1) = '\0';
    s = (char*) realloc(s, (len - whitespace_count + 1) * sizeof(char));
    
    return s;
}

int main(int argc, char** argv) {
    char* ans;
    char* w1 = (char*) malloc(sizeof(char) * strlen("the sky is blue") + 1);
    char* w2 = (char*) malloc(sizeof(char) * strlen("  hello world  ") + 1);
    char* w3 = (char*) malloc(sizeof(char) * strlen("a good  example") + 1);

    strcpy(w1, "the sky is blue");
    strcpy(w2, "  hello world  ");
    strcpy(w3, "a good  example");

    ans = reverseWords(w1);
    printf("'%s'\n", ans);
    free(ans);

    ans = reverseWords(w2);
    printf("'%s'\n", ans);
    free(ans);

    ans = reverseWords(w3);
    printf("'%s'\n", ans);
    free(ans);
}
