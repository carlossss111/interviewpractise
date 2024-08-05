/*
3. Longest Substring Without Repeating Characters
Medium

Given a string s, find the length of the longest substring without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Constraints:
0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/

/*
The brute force approach would be to go through each char and then get the longest after it, that would
be O(n^2).

The optimised approach would be to create a window between two pointers.
If a character has not been used twice, move the top pointer up, if a character has been used twice, move
the bottom pointer up. Get the max length between these pointers.
*/


int lengthOfLongestSubstring(char* s) {
    char ascii_occurances[256];
    char* top = s;
    char* bottom = s;
    
    int longest = 0;
    int window = 0;
    
    ascii_occurances[*top] = 1;
    
    while(*top != '\0'){
        if (ascii_occurances[*top] <= 1){
            top++;
            ascii_occurances[*top]++;
            
            window++;
        }
        else{
            ascii_occurances[*bottom]--;
            bottom++;
            
            window--;
        }
        
        if(window > longest){
            longest = window;
        }
    }
    
    return longest;
}