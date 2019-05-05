/*Given a binary tree, flatten it to a linked list in-place.

Example :
Given


         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
Note that the left child of all nodes should be NULL.*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 void PreOrder(TreeNode* A , queue <TreeNode*> &Q)
 {
     if(A==NULL)
     return;
     
     Q.push(A);
     PreOrder(A->left,Q);
     PreOrder(A->right,Q);
 }
TreeNode* Solution::flatten(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    queue <TreeNode*> Q;
    TreeNode* curr=A;
    TreeNode* root=A;
    
    if(A==NULL || (A->left==NULL && A->right==NULL))
    return A;
    
    PreOrder(A,Q);
    
    curr=Q.front();
    root=Q.front();
    curr->left=NULL;
    Q.pop();
    
    while(!Q.empty())
    {
       curr->right=Q.front();
       curr->left=NULL;
       curr=curr->right;
       Q.pop();
    }
    
    return root;
    
    
}
