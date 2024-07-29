#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Method:
Notice that when a digit in a node is added together, if they overflow then the carry
can be added to the next node.
Therefore, loop through every node, calculate a sum and a carry, and add the carry
into the next node. Rinse repeat.
*/

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* result = (struct ListNode*) malloc(sizeof(struct ListNode));
    struct ListNode* r_current = result;
    int carry = 0;
    
    while(l1 || l2){
        // Add sum
        int digit_sum;
        if(l1 && l2)
            digit_sum = l1->val + l2->val + carry;
        else if (l1)
            digit_sum = l1->val + carry;
        else if (l2)
            digit_sum = l2->val + carry;
        
        carry = 0;
        if(digit_sum > 9){
            digit_sum %= 10;
            
            // Handle overflow
            carry++;
        }
        
        // Iterate
        if(l1)
            l1 = l1->next;
        if(l2)
            l2 = l2->next;
        
        r_current->val = digit_sum;
        if(l1 || l2){
            r_current->next = (struct ListNode*) malloc(sizeof(struct ListNode));
            r_current = r_current->next;
        }
        else{
            r_current->next = NULL;
        }
    }
    
    // If there is still a carry left, add an extra node.
    if(carry > 0){
        r_current->next = (struct ListNode*) malloc(sizeof(struct ListNode));
        r_current = r_current->next;
        r_current->val = carry;
        r_current->next = NULL;
    }
    
    return result;
}
