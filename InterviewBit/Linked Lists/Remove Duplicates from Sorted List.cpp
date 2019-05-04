/*Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    
    if(A==NULL)
    return A;
    if(A->next==NULL)
    return A;
    ListNode* temp1=A;
    ListNode* temp2=A->next;
    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1->val==temp2->val)
        {
            temp1->next=temp2->next;
            free(temp2);
            temp2=temp1->next;
        }
        else
        {
            temp1=temp1->next;
            temp2=temp2->next;
        }
    }
    return A;
}
