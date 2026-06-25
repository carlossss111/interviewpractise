/*
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

Constraints:

    1 <= nums.length <= 104
    0 <= nums[i] <= 105
*/

// The model answer works by keeping track of the furthest index you can jump to.
// If at any point you pass that point without updating it, then you know you must've reached a failure state.

#include <stdio.h>
#include <stdbool.h>

bool canJumpModelAnswer(int* nums, int numsSize) {
    int maxReach = 0;

    for (int i = 0; i < numsSize; i++) {
        if (i > maxReach)
            return false;

        if (i + nums[i] > maxReach)
            maxReach = i + nums[i];
    }

    return true;
}

// My attempt was filled with edge cases unfortunately, but it just about worked.
// The idea was to find zeroes, calculate the size of the gap, then go backwards. It takes longer than the model answer.

bool canJumpBadAnswer(int* nums, int numsSize) {
    if (numsSize > 1 && nums[0] == 0){
        return false;
    }


    for (int i = 0; i < numsSize; i++) {

        if (nums[i] == 0) {

            // Go forward to calculate the gap that we need to jump past
            int j = i;
            int gap = 0;
            while(j < numsSize && nums[j] == 0){
                gap += 1;
                j++;
            }

            // Go back to search for a number that lets us cross the gap
            j = i - 1;
            while(j >= 0 && (nums[j] + j != numsSize-1) && nums[j] < (gap + i - j)){
                j--;

                // If we reach the start, no number can cross
                if (j < 0){
                    return false;
                }
            }

            // Skip the other zeroes in the gap
            i += gap - 1;
        }
    }
    return true;
}

int main(int argc, char** argv) {
    bool ans = canJumpModelAnswer((int[]) {3,2,1,0,1}, 5);
    printf("%d\n", ans);
    return 0;
}

