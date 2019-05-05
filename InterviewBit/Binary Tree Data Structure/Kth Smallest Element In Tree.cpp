/*Given a binary search tree, write a function to find the kth smallest element in the tree.

Example :

Input : 
  2
 / \
1   3

and k = 2

Return : 2

As 2 is the second smallest element in the tree.
 NOTE : You may assume 1 <= k <= Total number of nodes in BST */
 
 /**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int ans=0;

void inorder(TreeNode* A, int B, int &ind)
{
    if(A==NULL)
    return;
    
    if(ind>=B)
    return;
    
    inorder(A->left,B,ind);
    
    ++ind;
    if(ind==B)
    {
        ans=A->val;
        return;
    }

   
    inorder(A->right,B,ind);

    
    
}

int Solution::kthsmallest(TreeNode* A, int B) {
    
   
    int i=0;
    inorder(A,B,i);
    
    return ans;
    
}



