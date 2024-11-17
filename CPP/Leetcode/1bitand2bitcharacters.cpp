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

#include <cstdio>
#include <bitset>

// C VERSION
bool isOneBitCharacter(unsigned int bits, int bit_size) {
    if (bit_size == 1){
       return true;
    }
    if (bit_size == 2 && ((bits & (1 << 1)) == 0)){
        return true;
    } 

    int num_of_ones = 0;
    for(int i = 1; i < bit_size; i++){
        if ((bits & (1 << i)) == 0){
            break;
        }
        num_of_ones++;
    }
    if(num_of_ones % 2 == 0){
        return true;
    }
   return false;
}

// C++ VERSION
bool isOneBitCharacter2(unsigned int bits, int bit_size) {
    std::bitset<32> bitset(bits);
    if (bit_size == 1){
        return true;
    }
    if (bit_size == 2 && bitset[1] == 0){
        return true;
    }

    int num_of_ones = 0;
    for(int i = 1; i < bit_size; i++){
        if (bitset[i] == 0){
            break;
        }
        num_of_ones++;
    }
    if(num_of_ones % 2 == 0){
        return true;
    }
    return false;
}

int main(int argc, char** argv){
    unsigned int nums_in[] = {0b0111110, 0b011110, 0b0, 0b00, 0b10};
    int num_lens[] = {7,6,1,2,2};
    for (int i = 0; i < 5; i++){
        bool result = isOneBitCharacter(nums_in[i], num_lens[i]);
        if(result){
            printf("C: %d - True\n", nums_in[i]);
        }
        else{
            printf("C: %d - False\n", nums_in[i]);
        }

        bool result2 = isOneBitCharacter2(nums_in[i], num_lens[i]);
        if(result){
            printf("C++: %d - True\n", nums_in[i]);
        }
        else{
            printf("C++: %d - False\n", nums_in[i]);
        }
    }
}

