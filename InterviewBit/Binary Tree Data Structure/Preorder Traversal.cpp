/*Given a binary tree, return the preorder traversal of its nodes’ values.

Example :
Given binary tree

   1
    \
     2
    /
   3
return [1,2,3].

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
vector<int> Solution::preorderTraversal(TreeNode* A) {
    
    vector <int> res;
    stack <TreeNode* > S;
    TreeNode* curr=A;
    
    while(1)
    {
        while(curr!=NULL)
        {
            res.push_back(curr->val);
            //cout<<curr->val;
            S.push(curr);
            curr=curr->left;
        }
        
        if(S.empty())
        break;
        
        curr=S.top();
        curr=curr->right;
        S.pop();
    }
    
    return res;
}
