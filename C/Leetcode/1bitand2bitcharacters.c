/*
717. 1-bit and 2-bit Characters
Easy

We have two special characters:
    The first character can be represented by one bit 0.
    The second character can be represented by two bits (10 or 11).

Given a binary array bits that ends with 0, return true if the last character must be a one-bit character.

Example 1:
Input: bits = [1,0,0]
Output: true
Explanation: The only way to decode it is two-bit character and one-bit character.
So the last character is one-bit character.

Example 2:
Input: bits = [1,1,1,0]
Output: false
Explanation: The only way to decode it is two-bit character and two-bit character.
So the last character is not one-bit character.

Constraints:
    1 <= bits.length <= 1000
    bits[i] is either 0 or 1.

*/
#include <stdbool.h>

/*
The patterns for a good solution:
     0 -> True
 ...00 -> True
 ...10 -> ?
...110 -> True
...010 -> False
*/

bool isOneBitCharacter(int* bits, int bitsSize) {
    int end = bitsSize - 1;
    // Base Cases
    if (bitsSize == 1){
        return true;
    }
    if (bitsSize == 2 && bits[end-1] == 0){
        return true;
    }

    // If the remaining number of ones is even, it is true
    int num_of_ones = 0;
    for(int i = end-1; i >= 0; i--){
        if(bits[i] == 0){
            break;
        }
        num_of_ones++;
    }
    if(num_of_ones % 2 == 0){
        return true;
    }
    return false;
}

