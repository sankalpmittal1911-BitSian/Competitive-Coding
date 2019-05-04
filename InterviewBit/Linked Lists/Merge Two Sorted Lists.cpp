/*Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.

For example, given following linked lists :

  5 -> 8 -> 20 
  4 -> 11 -> 15
The merged list should be :

4 -> 5 -> 8 -> 11 -> 15 -> 20*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ListNode * temp1;
    ListNode * temp2;
    ListNode * prev;
    ListNode* temp;
    prev=NULL;
    temp1=A;temp2=B;
    while(temp1!=NULL&&temp2!=NULL){
        if(temp2->val<=temp1->val){
            if(prev==NULL){
                prev=temp2;
                A=temp2;
                temp2=temp2->next;
                prev->next=temp1;
            }
            else{
            prev->next=temp2;
            temp=temp2->next;
            temp2->next=temp1;
            temp2=temp;
            prev=prev->next;}
        }
        else{
            if(prev==NULL){
                prev=temp1;
                temp1=temp1->next;
            }
            else{
                    if(temp1->next==NULL){
                        temp1->next=temp2;
                        return A;
                    }
                    else{
                        temp1=temp1->next;
                        prev=prev->next;
                    }
            }
        }
    }
    return A;
    
}
