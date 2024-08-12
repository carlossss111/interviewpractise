/*
26. Remove Duplicates from Sorted Array
Easy

Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:
    Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
    Return k.

Example 1:
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

Example 2:
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

Constraints:
    1 <= nums.length <= 3 * 104
    -100 <= nums[i] <= 100
    nums is sorted in non-decreasing order.
*/

/*
Naive approach: loop through every element and downshift at every duplicate.
Better approach: maintain 2 pointers. One holds the place in list and the other finds the next val up. O(n) time O(1) space.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void debugPrintArr(int* nums, int numsSize){
    for(int i = 0; i < numsSize; i++){
        printf("%d ", nums[i]);
    }
    putchar('\n');
}

int removeDuplicates(int* nums, int numsSize) {
    if(numsSize == 1)
        return 1;
    
    int lastnum = *nums;
    
    int* ptrA = nums + 1;
    int* ptrB = nums + 1;
    int uniqueCount = 1;
    
    for(int i = 1; i < numsSize; i++){
        if(*ptrB > lastnum){
            swap(ptrA, ptrB);
            lastnum = *ptrA;
            ptrA++;
            uniqueCount++;
        }
        
        ptrB++;
    }
    
    return uniqueCount;
}