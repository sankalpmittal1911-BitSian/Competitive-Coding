/*Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

Example :

    1
   / \
  2   2
 / \ / \
3  4 4  3
The above binary tree is symmetric. 
But the following is not:

    1
   / \
  2   2
   \   \
   3    3
Return 0 / 1 ( 0 for false, 1 for true ) for this problem*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int Symm(TreeNode* A1, TreeNode* A2)
{
    if(A1==NULL && A2==NULL)
    return 1;
    
    if(A1 && A2 && A1->val==A2->val && Symm(A1->left,A2->right) && Symm(A1->right, A2->left))
    return 1;
    
    return 0;
}

int Solution::isSymmetric(TreeNode* A) {
    
    if(A==NULL)
    return 1;
    
    if(A->right==NULL && A->left==NULL)
    return 1;
    
    return Symm(A->left,A->right);
    
}
