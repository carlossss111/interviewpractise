/* 1.
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]

Constraints:

    2 <= nums.length <= 104
    -109 <= nums[i] <= 109
    -109 <= target <= 109
    Only one valid answer exists.
*/

/*
solution: make a hashmap where the key is the number needed to reach the target and the value is the index
*/

#include <stdio.h>
#include <unordered_map>
#include <vector>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::vector<int> answer;
    std::unordered_map<int, int> mymap;

    for (int i = 0; i < nums.size(); i++){
        int elem = nums[i];
        if (mymap.find(elem) != mymap.end()){ //contains

            // Result Found
            int index = mymap[elem];
            answer.push_back(i);
            answer.push_back(index);
            break;
        }

        mymap[target - elem] = i;
    }
    return answer;
}

int main(int argc, char** argv) {
    std::vector<int> e1 = {2, 7, 11, 15};
    std::vector<int> e2 = {3, 2, 4};
    std::vector<int> e3 = {3, 3};

    auto r1 = twoSum(e1, 9);
    printf("[%d,%d]\n", r1[0], r1[1]);
    auto r2 = twoSum(e2, 6);
    printf("[%d,%d]\n", r2[0], r2[1]);
    auto r3 = twoSum(e3, 6);
    printf("[%d,%d]\n", r3[0], r3[1]);

    return 0;
}

