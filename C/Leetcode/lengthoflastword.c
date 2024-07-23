/*
 * 58. Length of Last Word
Easy

Given a string s consisting of words and spaces, return the length of the last word in the string.
A word is a maximal substring consisting of non-space characters only.

Example 1:
Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.

Example 2:
Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.

Example 3:
Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.

Constraints:
1 <= s.length <= 104
s consists of only English letters and spaces ' '.
There will be at least one word in s.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define isletter(c) ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))

int solution(char* str){
	int len = 0;
	int lastlen = 0;
	char* lastwrd = str;

	while(*str != '\0'){
		if (!isletter(*str)){
			lastwrd = str;
			if(len != 0)
				lastlen = len;
			len = 0;
		}
		else {
			len++;
		}
		str++;
	}

	if(len == 0){
		len = lastlen;
	}
	return len;
}

int main(int argc, char** argv){
	printf("%d\n", solution(argv[1]));
	return 0;
}
