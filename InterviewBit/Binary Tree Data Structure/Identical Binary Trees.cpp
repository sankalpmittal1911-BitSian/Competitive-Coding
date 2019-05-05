/*Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Example :

Input : 

   1       1
  / \     / \
 2   3   2   3

Output : 
  1 or True*/
  
  /**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void inorder(TreeNode* root , vector<int> &X)
{
    if(root==NULL)
    return;
    
    inorder(root->left , X);
    X.push_back(root->val);
    inorder(root->right, X);
    
    
}

int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    
    vector <int> X1;
    vector <int> X2;
    
    inorder(A,X1);
    inorder(B,X2);
    
    if(X1.size()!=X2.size())
    return 0;
    
    for(int i=0;i<X1.size();++i)
    {
        if(X1[i]!=X2[i])
        return 0;
    }
    
    return 1;
}
