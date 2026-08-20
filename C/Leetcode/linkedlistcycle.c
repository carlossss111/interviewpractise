/*
141. Linked List Cycle
Solved
Easy
Topics
premium lock iconCompanies

Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

Example 2:

Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

Example 3:

Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.

Constraints:

    The number of the nodes in the list is in the range [0, 104].
    -105 <= Node.val <= 105
    pos is -1 or a valid index in the linked-list.

Follow up: Can you solve it using O(1) (i.e. constant) memory?

*/

#include <stdio.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

 // This is called Floyd's Tortoise and Hare algorithm

typedef struct ListNode ListNode;

bool hasCycle(struct ListNode *head) {
    ListNode* slow_ptr = head;
    ListNode* fast_ptr = head;

    if (!head) {
        return false;
    }

    for (;;) {
        // Advance fast_ptr twice
        if(fast_ptr->next) {
            fast_ptr = fast_ptr->next;
        }
        else {
            break;
        }
        if(fast_ptr->next) {
            fast_ptr = fast_ptr->next;
        }
        else {
            break;
        }

        // Advance slow_ptr once
        slow_ptr = slow_ptr->next;

        // If the slow_ptr and fast_ptr match, we have a cycle
        if (slow_ptr == fast_ptr) {
            return true;
        }
    }
    return false; //no cycle, we have reached NULL
}

int main(int argc, char** argv) {
    ListNode first = {1, NULL};
    ListNode second= {2, &first};
    first.next = &second;

    bool res = hasCycle(&first);
    printf("%d\n", res);

    return 0;
}

