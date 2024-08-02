/*
Q: Given two strings, write a method to decide if one is a permutation of the other.

b)
"abcd", "acbd" => true
"abcd", "aead" => false
"abcd", "acbdd" => false

c)
brute force would be to loop through each character of the first and of the second string, and check
they are there. this would be O(n^2) time

d)
observations:
- where the length is different, it must be false
- where there are letters that dont match, it is false.

I could loop through strA and add each value to a hashmap, then loop through strB and check each value.
This would give me O(n) time and O(n) space.
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unordered_map>

bool isPermutation(const char* strA, const char* strB) {
    std::unordered_map<char, int> map;
    // In hindsight, a hashmap was unnessecary and this could've just been done with
    // an array where the ASCII value is the index.
    if(strlen(strA) != strlen(strB)){
        return false;
    }

    while(*strA != '\0'){
        if(map.count(*strA)){
            int val = map.at(*strA);
            map.insert_or_assign(*strA, ++val);
        }
        else{
            map.insert_or_assign(*strA, 1);
        }

        strA++;
    }

    while(*strB != '\0'){
        if(map.count(*strB)){
            int val = map.at(*strB);
            map.insert_or_assign(*strB, --val);
            if(val < 0){
                return false;
            }
        }
        else{
            return false;
        }
        strB++;
    }
    return true;
}

// The book tells me another solution that I hadn't considered.
// When sorted, both strings will have the same value, so they could both just be sorted.

int main(int argc, char** argv) {
    bool result = isPermutation("abcc", "cbac");
    printf("%s\n", result ? "True" : "False");
}