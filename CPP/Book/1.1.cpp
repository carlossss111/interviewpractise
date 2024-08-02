/*
Q: Implement an algorithm to determine if a string has all unique characters. 
What if you cannot use additional data structures?

SOLVING METHOD:
a) listen 
b) example
c) brute force
d) optimize
e) walkthrough
f) implement
g) test

b)
"abcdefghijk" => true
"abcdefggggg" => false

c)
brute force would be to check every character against the entire string.
this would be O(n^2)

d)
could store each value in a hash-table as I continue, accessing it would be O(1) so the final algorithm would
be O(n)

if ASCII, could store each ascii value in an array and then attempt to access it. final O(n) time

if I couldn't use additional data structs, then we could either brute force or sort the string 
alphabetically
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>

//O(n) time, up to O(n) space
bool isUnique(const char* str) {
    std::set<char> charset;

    while(*str != '\0'){
        if(charset.contains(*str)){ //req std=c++20
            return false;
        }
        else{
            charset.insert(*str);
        }

        str++;
    }

    return true;
}

//O(n) time, O(1) space
//assumes 26 characters, a-z
bool isUniqueBetter(const char* str) {
    unsigned int charset = 0; // 32 bits

    while(*str != '\0') {
        unsigned int c = (unsigned int) *str - 'a';
        c = (1 << c);

        if(charset & c > 0){
            return false;
        }

        charset |= c;
    }
    return true;
}

int main(int argc, char** argv) {
    bool result = isUnique("abcdefghijk");
    printf("%s\n", result ? "True" : "False");
}