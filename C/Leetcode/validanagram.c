/*
 
   Given two strings s and t, return true if t is an of s, and false otherwise.



Example 1:

Input: s = "anagram", t = "nagaram"

Output: true

Example 2:

Input: s = "rat", t = "car"

Output: false



Constraints:

    1 <= s.length, t.length <= 5 * 104
    s and t consist of lowercase English letters.
*/
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

bool isAnagram(char* s, char* t) {
    uint32_t ascii[256] = {0};

    if (strlen(s) != strlen(t)){
        return false;
    }

    while(*s != '\0') {
        ascii[*s]++;
        s++;
    }

    while(*t != '\0') {
        ascii[*t]--;
        t++;
    }

    for (int i = 0; i < 256; i++) {
        if (ascii[i] != 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, char** argv) {
    bool ans = isAnagram("anagram", "nagaram");
    printf("%d\n",ans);
    return 0;
}

