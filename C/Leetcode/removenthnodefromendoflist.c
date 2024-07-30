/*
19. Remove Nth Node From End of List
Medium

Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Naive Approach:
Loop through the entire list once to get the length of the list.
Then, loop through again to the correct position and remove it.
This would be 2n time.

Better Approach(?):
Loop through entire list and create another list in the opposite direction.
At the end, just go back a few steps.
This would be n time but more space complex.
*/

struct ListNode {
    int val;
    struct ListNode *next;
};
 
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* listarr[30];
    struct ListNode* current = head;
    int len;
    
    // Populate array of ptrs
    // Uses 240 bytes of extra memory
    int i = 0;
    while(current){
        listarr[i] = current;
        i++;
        current = current->next;
    }
    len = i;
    
    // Remove the target node
    int target = len - n;
    if(target != 0 && target != len - 1)
        listarr[target-1]->next = listarr[target+1];
    else if (target == 0)
        head = listarr[target+1];
    else if (target == len - 1)
        listarr[target-1]->next = NULL;
        
    return head;
}