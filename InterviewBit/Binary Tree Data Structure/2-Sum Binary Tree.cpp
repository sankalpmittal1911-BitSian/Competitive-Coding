/*Given a binary search tree T, where each node contains a positive integer, and an integer K, you have to find whether or not there exist two different nodes A and B such that A.value + B.value = K.

Return 1 to denote that two such nodes exist. Return 0, otherwise.

Notes

Your solution should run in linear time and not take memory more than O(height of T).
Assume all values in BST are distinct.
Example :

Input 1: 

T :       10
         / \
        9   20

K = 19

Return: 1

Input 2: 

T:        10
         / \
        9   20

K = 40

Return: 0*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int Search(TreeNode* A,int value)
{
   if(A==NULL)
   return 0;
   
   if(value==A->val)
   return 1;
   
   else if (value<A->val)
   return Search(A->left,value);
   
   else if(value>A->val)
   return Search(A->right,value);
   
}


void inorder(TreeNode* A,int B,int &flag, TreeNode* temp)
{
    if(A==NULL)
    return;
    
    inorder(A->left,B,flag,temp);
    //cout<<Search(temp,B-A->val);
    if(B-A->val!=A->val && Search(temp,B-A->val))
    flag=1;
    //cout<<flag;
    inorder(A->right,B,flag,temp);
    
    
}

int Solution::t2Sum(TreeNode* A, int B) {
    
    int flag=0;
    
    inorder(A,B,flag,A);
    
    return flag;
}
