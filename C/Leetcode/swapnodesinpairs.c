/*
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

Input: head = [1,2,3,4]

Output: [2,1,4,3]

Example 2:

Input: head = []

Output: []

Example 3:

Input: head = [1]

Output: [1]

Example 4:

Input: head = [1,2,3]

Output: [2,1,3]
*/

/*

   solution was to process in groups of four.
   A,-> B,-> C,-> D

   1. Make B point to A
   2. Make A point to D IF D is not NULL
   3. Else make A point to C (regardless of whether C is NULL)
   4. Move on with C being the new A, D the new B, etc.

   O(n) time, O(1) space

*/

#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode* node = head;
    struct ListNode* new_head = head;

    if (!head) {
        return NULL;
    }

    if (node->next) {
        new_head = node->next;
    }

    while (node) {
        // Get node group
        struct ListNode* first_node = node;
        struct ListNode* middle_node = node->next;
        if(!middle_node) {
            break;
        }
        struct ListNode* last_node = middle_node->next;

        // Switch up
        middle_node->next = first_node;
        first_node->next = last_node;
        if (last_node && last_node->next) {
            first_node->next = last_node->next;
        }
        else{
            first_node = last_node;
        }

        // Move on to next group
        node = last_node;
    }

    return new_head;
    
}

int main(int argc, char** argv) {
    //
}

