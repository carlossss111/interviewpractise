/*
14. Longest Common Prefix
Easy

Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Constraints:
1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool allequal(char** strs, int strsSize, int cIndex){
    for(int i = 0; i < strsSize; i++){
        if(strs[i][cIndex] == '\0'){
            return false;
        }
        if(strs[i][cIndex] != strs[0][cIndex]){
            return false;
        }
    }
    return true;
}

char* longestCommonPrefix(char** strs, int strsSize) {
    int len = 0;
    
    while(allequal(strs, strsSize, len)){
        len++;
    }
    
    char* prefix = (char*) malloc(sizeof(char) * (len + 1));
    sprintf(prefix, "%.*s", len, strs[0]);
    return prefix;
}