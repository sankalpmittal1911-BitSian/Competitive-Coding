/*Given a singly linked list

    L: L0 → L1 → … → Ln-1 → Ln,
reorder it to:

    L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
You must do this in-place without altering the nodes’ values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reorderList(ListNode* A) {
    
  
  int o_e=0,n=0,i=0;
  
  //Get length
  
  ListNode* temp1=A;
  while(temp1)
  {
      ++n;
      temp1=temp1->next;
  }
  
  temp1=A;
  
  if(n%2==0)
  o_e=0;
  else
  o_e=1;
  
  //Get Midpoint
  
  ListNode* temp2=A;
  ListNode* temp3=A;
  for(i=0;i<n/2+o_e;++i)
  {
      if(i==n/2 +o_e-2)
      temp3=temp2->next;
  temp2=temp2->next;
  }
  
  temp3->next=NULL;
  ListNode* prev=NULL;
  ListNode* curr=temp2;
  ListNode* next=NULL;
  
  while(curr)
  {
      next=curr->next;
      curr->next=prev;
      prev=curr;
      curr=next;
  }
  
  ListNode* head=prev;
  ListNode* temp11=temp1->next;
  while(temp1 && prev && temp11)
  {
      temp1->next=prev;
      prev->next=temp11;
      temp1=temp11;
      temp11=temp11->next;
      prev=prev->next;
  }
  
    return A;
}
