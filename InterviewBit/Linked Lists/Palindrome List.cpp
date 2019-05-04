/*Given a singly linked list, determine if its a palindrome. Return 1 or 0 denoting if its a palindrome or not, respectively.

Notes:

Expected solution is linear in time and constant in space.
For example,

List 1-->2-->1 is a palindrome.
List 1-->2-->3 is not a palindrome.*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


 ListNode* reverseSubList(ListNode* A, int B){
  ListNode *next, *current, *prev;
  int temp = B;
  prev = A;
  while(temp-- && prev != NULL){
    prev = prev -> next;
  }
  current = A;
  while (current != NULL && B--) {
    next = current -> next;
    current -> next = prev;
    prev = current;
    current = next;
  }
  return prev;
}


int Solution::lPalin(ListNode* A) {
  ListNode* temp = A;
  int count = 0;
  while (temp != NULL) {
    count++;
    temp = temp -> next;
  }
  int n = count/2;
  A = reverseSubList(A, n);
  temp = A;
  while(n--){
    temp = temp->next;
  }
  if (count % 2 == 1) {
    temp = temp -> next;
  }
  while(temp!= NULL){
    if (A->val != temp->val) {
      return 0;
    }
    A = A->next;
    temp = temp->next;
  }
  return 1;   
}
