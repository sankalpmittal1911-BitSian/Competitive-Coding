/*Given a binary tree, return the inorder traversal of its nodes’ values.

Example :
Given binary tree

   1
    \
     2
    /
   3
return [1,3,2].

Using recursion is not allowed.*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* A) {
    
    vector<int> res;
    
    if(!A)
    return res;
    
    stack<TreeNode* > S;
    
    TreeNode* curr=A;
    //TreeNode* temp=NULL;
    
    
    while(curr!=NULL || S.empty()==false)
    {
    
    while(curr!=NULL)
    {
      
      S.push(curr);
      curr=curr->left;
    }
    
    curr=S.top();
    S.pop();
    res.push_back(curr->val);
    
    curr=curr->right;
    //S.push(curr);
    
    //delete temp;
}

while(!S.empty())
{
res.push_back(S.top()->val);
S.pop();
}

return res;
}
