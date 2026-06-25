"""

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


Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
"""

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        o_ascii = {}

        if len(s) != len(t):
            return False

        for s_char in s:
            if s_char not in o_ascii:
                o_ascii[s_char] = 1
            else:
                o_ascii[s_char] += 1

        for t_char in t:
            if t_char not in o_ascii:
                return False
            else:
                o_ascii[t_char] -= 1

        if all(v == 0 for v in o_ascii.values()):
            return True
        return False
        

if __name__ == "__main__":
    ans = Solution().isAnagram("anagram", "nagaram")
    print(ans)

