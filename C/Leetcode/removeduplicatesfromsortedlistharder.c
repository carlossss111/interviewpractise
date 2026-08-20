/*
82. Remove Duplicates from Sorted List II
Solved
Medium
Topics
premium lock iconCompanies

Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

Example 1:

Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]

Example 2:

Input: head = [1,1,1,2,3]
Output: [2,3]

Constraints:

    The number of nodes in the list is in the range [0, 300].
    -100 <= Node.val <= 100
    The list is guaranteed to be sorted in ascending order.
*/

// bit unhinged, but just have to draw it out and look for edge cases

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;

struct ListNode* deleteDuplicates(struct ListNode* head) {
    ListNode* current = head;
    ListNode* last = NULL;
    ListNode* base = NULL;

    ListNode* first_base = NULL;

    if (!head) {
        return NULL;
    }
    if (!head->next) {
        return head;
    }

    while(current) {
        if (!last || (last->val != current->val)) {

            if (base) {
                base->next = current;
            }
            last = current;

            if (!current->next || current->next->val != current->val) {
                base = current;

                if (!first_base) {
                    first_base = base;
                }
            }
        }

        current = current->next;
    }

    if (last->next && last->next->val == last->val && base) {
        base->next = NULL;
    }

    return first_base;
}

int main(int argc, char** argv) {
    ListNode n5 = {3, NULL};
    ListNode n4 = {2, &n5};
    ListNode n3 = {1, &n4};
    ListNode n2 = {1, &n3};
    ListNode head = {1, &n2};

    ListNode* curr = deleteDuplicates(&head);

    while (curr) {
        printf("%d ", curr->val);
        curr = curr->next;
    }
    putchar('\n');
    
    return 0;
}

