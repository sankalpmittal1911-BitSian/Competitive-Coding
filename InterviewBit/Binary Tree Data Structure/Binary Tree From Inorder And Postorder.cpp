/*Given inorder and postorder traversal of a tree, construct the binary tree.

 Note: You may assume that duplicates do not exist in the tree. 
Example :

Input : 
        Inorder : [2, 1, 3]
        Postorder : [2, 3, 1]

Return : 
            1
           / \
          2   3*/
          
          /**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* Tree(vector <int> &in , vector <int> &pos, int in_st , int in_end, int &pInd, unordered_map<int,int>&M)
{
    if(in_st>in_end)
    return NULL;
    
    //int curr=pos[PInd]
    TreeNode* root=new TreeNode(pos[pInd]);
    //root->left=root->right=NULL;
    int curr=pos[pInd];
    --pInd;
    
    if(in_st==in_end)
    return root;
    
    
    int iInd= M[curr];
    
    root->right=Tree(in,pos,iInd+1,in_end,pInd,M);
    root->left=Tree(in,pos,in_st,iInd-1,pInd,M);
    
    return root;
    
    
    
}

TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    
    if(A.size()==0 || B.size()==0)
    return NULL;
    
    unordered_map<int,int>M;
    
    for(int i=0;i<A.size();++i)
    M[A[i]]=i;
    
    int pInd=B.size()-1;
    return Tree(A,B,0,A.size()-1,pInd,M);
}
