/*
190. Reverse Bits
Easy

Reverse bits of a given 32 bits unsigned integer.

Example 1:
Input: n = 00000010100101000001111010011100
Output:    964176192 (00111001011110000010100101000000)
Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, so return 964176192 which its binary representation is 00111001011110000010100101000000.

Example 2:
Input: n = 11111111111111111111111111111101
Output:   3221225471 (10111111111111111111111111111111)
Explanation: The input binary string 11111111111111111111111111111101 represents the unsigned integer 4294967293, so return 3221225471 which its binary representation is 10111111111111111111111111111111.

Constraints:
    The input must be a binary string of length 32

Follow up: If this function is called many times, how would you optimize it?
*/

#include <cstdint>
#include <cstdio>
#include <bitset>
#include <cstring>

/* SOLUTION 1 */

void swap(uint32_t* n, int i_left, int i_right){
    // Get bit at right and left
    uint32_t bit_at_left = *n & ((uint32_t) 1 << i_left);
    uint32_t bit_at_right = *n & ((uint32_t) 1 << i_right);
    
    // Clear right bit, then set if need
    *n &= ~((uint32_t) 1 << i_right);
    if (bit_at_left != 0){
        *n |= ((uint32_t) 1 << i_right);
    }

    // Clear left bit then set if need
    *n &= ~((uint32_t) 1 << i_left);
    if (bit_at_right != 0){
        *n |= ((uint32_t) 1 << i_left);
    }
}

void swap_cpp(uint32_t* n, int i_left, int i_right){
    // Get bits at left and right
    std::bitset<32> nbitset(*n);
    bool bit_at_left = nbitset[i_left];
    bool bit_at_right = nbitset[i_right];

    // Clear the right bit, then set if need
    nbitset.reset(i_right);
    if (bit_at_left){
        nbitset.set(i_right);
    }

    // Clear the left bit, then set if need
    nbitset.reset(i_left);
    if (bit_at_right){
        nbitset.set(i_left);
    }

    *n = (uint32_t) nbitset.to_ulong();
}

uint32_t reverseBits_1(uint32_t n) {
    int index_left = 31;
    int index_right = 0;
    
    while(index_left > index_right){ 
        
        swap(&n, index_left, index_right);
        
        index_left--;
        index_right++;
    }
    
    return n;
}

uint32_t reverseBits_1_cpp(uint32_t n) {
    int index_left = 31;
    int index_right = 0;
    
    while(index_left > index_right){ 
        
        swap_cpp(&n, index_left, index_right);
        
        index_left--;
        index_right++;
    }
    
    return n;
}

/* SOLUTION 2 */

uint32_t reverseBits_2(uint32_t n) {
    int input_i = 0;
    int output_i = 31;

    uint32_t result = 0;

    while(output_i >= 0){
        uint32_t bit_at_input = n & (1 << input_i);
        if(bit_at_input){
            result |= (1 << output_i);
        }

        input_i++;
        output_i--;
    }

    return result;
}

uint32_t reverseBits_2_cpp(uint32_t n){
    int input_i = 0;
    int output_i = 31;

    std::bitset<32> result_bitset(0);

    while(output_i >= 0){
        std::bitset<32> nbitset(n);
        bool bit_at_input = nbitset[input_i];
        if(bit_at_input){
            result_bitset.set(output_i);
        }

        input_i++;
        output_i--;
    }

    return (uint32_t) result_bitset.to_ulong();
}

int main(int argc, char** argv) {
    uint32_t myint = 43261596;
    uint32_t expected = 964176192;

    // Function pointer practise
    uint32_t (*solution) (uint32_t);
    if(strcmp(argv[1],"1") == 0){
        printf("C Swapping...\n");
        solution = reverseBits_1;       
    }
    if(strcmp(argv[1], "2") == 0){
        printf("C++ Swapping...\n");
        solution = reverseBits_1_cpp;
    }
    if(strcmp(argv[1], "3") == 0){
        printf("C Writing...\n");
        solution = reverseBits_2;
    }
    if(strcmp(argv[1], "4") == 0){
        printf("C++ Writing...\n");
        solution = reverseBits_2_cpp;
    }

    uint32_t result = solution(myint);

    printf("Result = %d\n", result);
    if (result == expected) {
        printf("Pass\n");
    }
    else {
        printf("Fail\n");
    }
    return 0;
}

