/*
205. Isomorphic Strings
Solved
Easy
Topics
premium lock iconCompanies

Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

Example 1:

Input: s = "egg", t = "add"

Output: true

Explanation:

The strings s and t can be made identical by:

    Mapping 'e' to 'a'.
    Mapping 'g' to 'd'.

Example 2:

Input: s = "f11", t = "b23"

Output: false

Explanation:

The strings s and t can not be made identical as '1' needs to be mapped to both '2' and '3'.

Example 3:

Input: s = "paper", t = "title"

Output: true

Constraints:

    1 <= s.length <= 5 * 104
    t.length == s.length
    s and t consist of any valid ascii character.

*/

// pretty simple, just make sure to note the mapping is two-way

#include <iostream>
#include <unordered_map>

bool isValid(std::unordered_map<char,char>& a_to_b, char key_char, char val_char) {
    // Key is not in map
    if (a_to_b.find(key_char) == a_to_b.end()){
        a_to_b[key_char] = val_char;
    }
    // Key is in map but the value doesnt match
    else if (a_to_b[key_char] != val_char) {
        return false;
    }
    return true;
}

bool isIsomorphic(std::string s, std::string t) {
    std::unordered_map<char, char> s_to_t = {};
    std::unordered_map<char, char> t_to_s = {};

    if (s.length() != t.length()) {
        return false;
    }

    for (int i = 0; i < s.length(); i++) {
        char key_char = s[i];
        char val_char = t[i];

        // Key is not in map in either direction
        if (!isValid(s_to_t, key_char, val_char) ||
            !isValid(t_to_s, val_char, key_char)) {
            return false;
        }
        // Otherwise continue
    }

    return true;
}

int main(int argc, char** argv) {
    std::string s = "paper";
    std::string t = "title";
    bool res = isIsomorphic(s, t);
    std::cout << res << std::endl << std::flush;
    return 0;
}

