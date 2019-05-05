/*Given a binary tree, return the zigzag level order traversal of its nodes’ values. (ie, from left to right, then right to left for the next level and alternate between).

Example : 
Given binary tree

    3
   / \
  9  20
    /  \
   15   7
return

[
         [3],
         [20, 9],
         [15, 7]
]*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    
    stack <TreeNode*> S1;
    stack <TreeNode*> S2;
    vector<int> X;
    vector<vector<int>> res;
    TreeNode* curr=A;
    if(A==NULL)
    return res;
    
    
    S1.push(curr);
    int k=0;
    
    while(!S1.empty() || !S2.empty())
    {
        ++k;
        
        if(k%2!=0)
        {
            while(!S1.empty())
            {
                curr=S1.top();
                X.push_back(curr->val);
                if(curr->left!=NULL)
                S2.push(curr->left);
                if(curr->right!=NULL)
                S2.push(curr->right);
                S1.pop();
            }
            res.push_back(X);
            X.clear();
        }
        
        else
        {
            while(!S2.empty())
            {
                curr=S2.top();
                X.push_back(curr->val);
                if(curr->right!=NULL)
                S1.push(curr->right);
                if(curr->left!=NULL)
                S1.push(curr->left);
                S2.pop();
                
            }
            
            res.push_back(X);
            X.clear();
        }
        
        
        
    }
    
    return res;
}
