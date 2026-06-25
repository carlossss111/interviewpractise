/*
 * Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Example 1:

Input: nums = [3,2,3]
Output: 3

Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2

Constraints:

    n == nums.length
    1 <= n <= 5 * 104
    -109 <= nums[i] <= 109
    The input is generated such that a majority element will exist in the array.


Follow-up: Could you solve the problem in linear time and in O(1) space?
*/

// This can be solved without the need of a hashmap using something called the Moore's Voting Algorithm.
// Basically, we can see that the candidate in the lead will always retain the lead or something

#include <stdio.h>

int majorityElement(int* nums, int numsSize) {
    int count = 0;
    int candidate = 0;

    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];

        if (count == 0) {
            candidate = num;
        }

        if (num == candidate) {
            count++;
        }
        else {
            count--;
        }
    }

    return candidate;
}

int main(int argc, char** argv) {
    int ans = majorityElement((int[]){2,2,1,1,1,2,2}, 7);
    printf("%d\n", ans);
    return 0;
}
