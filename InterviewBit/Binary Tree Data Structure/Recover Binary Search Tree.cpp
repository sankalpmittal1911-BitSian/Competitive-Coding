//This was difficult given the constraints.

/*Two elements of a binary search tree (BST) are swapped by mistake.
Tell us the 2 values swapping which the tree will be restored.

 Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution? 
Example :


Input : 
         1
        / \
       2   3

Output : 
       [1, 2]

Explanation : Swapping 1 and 2 will change the BST to be 
         2
        / \
       1   3
which is a valid BST      */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */



vector<int> Solution::recoverTree(TreeNode* A) {
    
     struct TreeNode *current, *pre; 
     vector<int> res;
     vector<int> x;
  
    if (A == NULL) 
        return res; 
  
    current = A; 
    while (current != NULL) { 
  
        if (current->left == NULL) { 
            x.push_back(current->val); 
            current = current->right; 
        } 
        else { 
  
           
            pre = current->left; 
            while (pre->right != NULL && pre->right != current) 
                pre = pre->right; 
  
            
            if (pre->right == NULL) { 
                pre->right = current; 
                current = current->left; 
            } 
  
           
            else { 
                pre->right = NULL; 
                x.push_back(current->val);
                current = current->right; 
            } 
        } 
    } 

    
    vector<int> y(x);
    sort(y.begin(),y.end());
    
    for(int i=0;i<x.size();++i)
    {
    if(x[i]!=y[i])
    res.push_back(x[i]);
    }
    
    x.clear();
    y.clear();
    
    reverse(res.begin(),res.end());
    return res;
    
    
}
