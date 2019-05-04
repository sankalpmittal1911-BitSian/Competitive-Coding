/*Sort a linked list in O(n log n) time using constant space complexity.

Example :

Input : 1 -> 5 -> 4 -> 3

Returned list : 1 -> 3 -> 4 -> 5*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */



ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
            if(l1 == NULL) return l2;
            if(l2 == NULL) return l1;

            ListNode* head = NULL;    // head of the list to return

            // find first element (can use dummy node to put this part inside of the loop)
            if(l1->val < l2->val) {
                head = l1;
                l1 = l1->next;
            } else {
                head = l2;
                l2 = l2->next;
            }

            ListNode* p = head;     // pointer to form new list

            while(l1 && l2){
                if(l1->val < l2->val) {
                    p->next = l1;
                    l1 = l1->next;
                } else {
                    p->next = l2;
                    l2 = l2->next;
                }
                p = p->next;
            }

            // add the rest of the tail, done!
            if (l1) {
                p->next=l1;
            } else {
                p->next=l2;
            }

            return head;
        }

ListNode* Solution::sortList(ListNode* A) {
    
    if (A == NULL || A->next == NULL)
                return A;

            // find the middle place
            ListNode *p1 = A;
            ListNode *p2 =A->next;
            while(p2 && p2->next) {
                p1 = p1->next;
                p2 = p2->next->next;
            }
            p2 = p1->next;
            p1->next = NULL;

            return mergeTwoLists(sortList(A), sortList(p2)); 
}

