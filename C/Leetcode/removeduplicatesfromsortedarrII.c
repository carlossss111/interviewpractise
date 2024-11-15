/*
Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place 
such that each unique element appears at most twice. The relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages, you must instead have the 
result be placed in the first part of the array nums. More formally, if there are k elements after 
removing the duplicates, then the first k elements of nums should hold the final result. 
It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

Custom Judge:

The judge will test your solution with the following code:
int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length
int k = removeDuplicates(nums); // Calls your implementation
assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.

Example 1:
Input: nums = [1,1,1,2,2,3]
Output: 5, nums = [1,1,2,2,3,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

Example 2:
Input: nums = [0,0,1,1,1,1,2,3,3]
Output: 7, nums = [0,0,1,1,2,3,3,_,_]
Explanation: Your function should return k = 7, with the first seven elements of nums being 0, 0, 1, 1, 2, 3 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

Constraints:
    1 <= nums.length <= 3 * 104
    -104 <= nums[i] <= 104
    nums is sorted in non-decreasing order.

*/
#include <stdio.h>

int new_pos(int current, int moves){
    return current - moves;
}


int remove_duplicates(int* nums, int nums_size) {
    int curr_index = 0;
    int last_num = *nums;
    int num_occurences = 1;
    int moves_down = 0;
    
    for(int i = 1; i < nums_size; i++){
        // Move down
        nums[new_pos(i, moves_down)] = nums[i];
        
        // Check last num
        if (nums[i] == last_num){
            num_occurences++;
            if (num_occurences > 2){
                moves_down++;
            }
        }
        else {
            num_occurences = 1;
            last_num = nums[i];
        }
    } 
    
    return nums_size - moves_down;
}

int main(int argc, char** argv) {
    int nums[8] = {1,1,1,2,2,2,3,4};

    int new_len = remove_duplicates(nums, 8);

    printf("New size = %d\n", new_len);
    for(int i = 0; i < new_len; i++){
        printf("%d, ", nums[i]);
    }
    putchar('\n');

    return 0;
}

