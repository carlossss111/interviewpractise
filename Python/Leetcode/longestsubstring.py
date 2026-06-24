"""
3. Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without duplicate characters.


Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.

Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
"""

# This is a classic SLIDING WINDOW problem

def lengthOfLongestSubstring(s: str) -> int:
    left = max_length = 0
    ascii_set = set()

    for right in range(len(s)):
        while s[right] in ascii_set:
            ascii_set.remove(s[left])
            left += 1

        ascii_set.add(s[right])

        if right - left + 1 > max_length:
            max_length = right - left + 1

    return max_length
    
def main():
    r1 = lengthOfLongestSubstring("dvdf")
    print(r1)

if __name__ == "__main__":
    main()


