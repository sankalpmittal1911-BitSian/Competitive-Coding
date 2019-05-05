/*Find the lowest common ancestor in an unordered binary tree given two values in the tree.

 Lowest common ancestor : the lowest common ancestor (LCA) of two nodes v and w in a tree or directed acyclic graph (DAG) is the lowest (i.e. deepest) node that has both v and w as descendants. 
Example :


        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2_     0        8
         /   \
         7    4
For the above tree, the LCA of nodes 5 and 1 is 3.

 LCA = Lowest common ancestor 
Please note that LCA for nodes 5 and 4 is 5.

You are given 2 values. Find the lowest common ancestor of the two nodes represented by val1 and val2
No guarantee that val1 and val2 exist in the tree. If one value doesn’t exist in the tree then return -1.
There are no duplicate values.
You can use extra memory, helper functions, and can modify the node struct but, you can’t add a parent pointer.*/


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int findPath(TreeNode* A, int N, vector <int> &X)
{
    if(A==NULL)
    return 0;
    
    X.push_back(A->val);
    
    if(A->val==N)
    return 1;
    
    if((A->left && findPath(A->left, N, X)) ||(A->right && findPath(A->right,N,X)) )
    return 1;
    
    
        X.pop_back();
        return 0;
    
}

int Solution::lca(TreeNode* A, int B, int C) {
    
    vector <int> X1,X2;
    
    if(!findPath(A,B,X1) || !findPath(A,C,X2))
    return -1;
    
    int i;
    
    for(i=0;i< min(X1.size(),X2.size()); ++i)
    {
        //cout<<X1[i];
       if(X1[i]!=X2[i])
       break;
    }
    
    return X1[i-1];
    
}

//Think of better logic
