/*
28. Find the Index of the First Occurrence in a String
Easy

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Example 2:
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1. 

Constraints:
1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solution(char* haystack, char* needle){
	int nindex = 0;
	int sindex = 0;
	int needlelen = strlen(needle);
	int startindex = -1;

	for(sindex = 0; sindex < strlen(haystack); sindex++){
		startindex = -1;
		nindex = 0;
		int i = sindex;
		if(haystack[i] == needle[nindex]){
			startindex = sindex;
		}

		while(haystack[i] == needle[nindex]){
			nindex++;
			i++;
			if(needle[nindex] == '\0'){
				return startindex;
			}
		}
	}
	return -1;
}

int main(int argc, char** argv){
	printf("%d\n", solution("sadbutsad", "ad"));
	return 0;
}
