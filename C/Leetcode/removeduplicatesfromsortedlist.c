/*
Given the head of a sorted linked list, delete all duplicates such that each element appears only 
once. Return the linked list sorted as well.
 
Example 1:
Input: head = [1,1,2]
Output: [1,2]

Example 2:
Input: head = [1,1,2,3,3]
Output: [1,2,3]

Constraints:
    The number of nodes in the list is in the range [0, 300].
    -100 <= Node.val <= 100
    The list is guaranteed to be sorted in ascending order.
*/
#include <stdlib.h>
#include <stdio.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
}ListNode;


struct ListNode* deleteDuplicates(struct ListNode* head){
    if (!head || !head->next){
        return head;
    }

    ListNode* current = head->next;
    ListNode* prev = head;

    while(current){
        if(current->val <= prev->val){
            current = current->next;
            prev->next = current;
        }
        else {
            current = current->next;
            prev = prev->next;
        }
    }

    return head;
}

int main(int argc, char** argv){
    ListNode first;
    ListNode second;
    ListNode third;

    first.val = 1;
    first.next = &second;
    second.val = 1;
    second.next = &third;
    third.val = 2;
    third.next = NULL;

    ListNode* ptr = deleteDuplicates(&first);

    while(ptr){
        printf("%d,", ptr->val);
        ptr = ptr->next;
    }

    return 0;
}
