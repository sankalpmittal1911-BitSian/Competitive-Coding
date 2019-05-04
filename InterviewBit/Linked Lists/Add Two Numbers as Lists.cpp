/*You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

    342 + 465 = 807
Make sure there are no trailing zeros in the output list
So, 7 -> 0 -> 8 -> 0 is not a valid response even though the value is still 807.*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    
    if(A == NULL){
        return B;
    }
    else if(B == NULL){
        return A;
    }
    
    // reversing the list
    
    ListNode* currA = A;
    ListNode* currB = B;
    
    ListNode* ans = NULL;
    ListNode* head;
    
    int sum, carry = 0, value;
    while(currA != NULL && currB != NULL){
        sum = currA->val + currB->val + carry;
        carry = sum/10;
        value = sum%10;
        
        ListNode* store = new ListNode(value);
        
        if(ans == NULL){
            ans = store;
            head = ans;
        }
        else{
            ans->next = store;
            ans = store;
        }
        currA = currA->next;
        currB = currB->next;
    }
    
    if(currA == NULL){
        while(currB != NULL){
            sum = currB->val + carry;
            carry = sum/10;
            value = sum%10;
            
            ListNode* store = new ListNode(value);
            
            ans->next = store;
            ans = store;
            
            currB = currB->next;
        }
    }
    else if(currB == NULL){
        while(currA != NULL){
            sum = currA->val + carry;
            carry = sum/10;
            value = sum%10;
            
            ListNode* store = new ListNode(value);
            
            ans->next = store;
            ans = store;
            
            currA = currA->next;
        }
    }
    
    if(carry != 0){
        ListNode* store = new ListNode(carry);
        
        ans->next = store;
        ans = store;
    }

    return head;
}
