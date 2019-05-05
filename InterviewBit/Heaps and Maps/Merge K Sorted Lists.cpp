/*Merge k sorted linked lists and return it as one sorted list.

Example :

1 -> 10 -> 20
4 -> 11 -> 13
3 -> 8 -> 9
will result in

1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    
    priority_queue <int, vector<int>, greater<int> > pq; 
    
    for(int i=0;i<A.size();++i)
    {
        ListNode* temp=A[i];
        while(temp!=NULL)
        {
            pq.push(temp->val);
            temp=temp->next;
        }
    }
    
    ListNode* head=new ListNode(pq.top());
    ListNode* curr=head;
    pq.pop();
    
    while(pq.empty()==false)
    {
            curr->next= new ListNode(pq.top());
            curr=curr->next;
            pq.pop();
            
        
    }
    
    curr->next = NULL;
    
    return head;
}

