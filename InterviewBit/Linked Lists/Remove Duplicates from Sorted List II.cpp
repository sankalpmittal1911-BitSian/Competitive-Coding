/*Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(A==NULL || A->next==NULL) return A;
    ListNode* start = new ListNode(0);
    start->next=A;
    ListNode* curr=start;
    ListNode* temp;
    while(curr->next!=NULL)
    {
        temp=curr->next;
        while(temp->next!=NULL && temp->val==temp->next->val)
            temp=temp->next;
        if(curr->next==temp) curr=curr->next;
        else curr->next=temp->next;
    }
    return start->next;
}

