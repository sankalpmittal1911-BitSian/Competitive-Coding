/*Given a binary tree, return the postorder traversal of its nodes’ values.

Example :

Given binary tree

   1
    \
     2
    /
   3
return [3,2,1].

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
vector<int> Solution::postorderTraversal(TreeNode* A) {
    
    TreeNode* curr=A;
    stack <TreeNode*> S;
    vector <int> res;
    
    while(1)
    {
       
       
        while(curr!=NULL)
        {
            S.push(curr);
            S.push(curr);
            curr=curr->left;
        }
        
         if(S.empty())
       break;
       
       curr=S.top();
       S.pop();
       
       if(!S.empty() && curr==S.top())
       curr=curr->right;
       else
       {
           res.push_back(curr->val);
           curr=NULL;
       }
       
      
        
        
        
        
        
    }
    
    return res;
}
