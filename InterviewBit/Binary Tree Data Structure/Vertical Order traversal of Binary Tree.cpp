/*Given a binary tree, return a 2-D array with vertical order traversal of it.
Go through the example and image for more details.

Example :
Given binary tree:

      6
    /   \
   3     7
  / \     \
 2   5     9
returns

[
    [2],
    [3],
    [6 5],
    [7],
    [9]
]


Note : If 2 Tree Nodes shares the same vertical level then the one with lesser depth will come first.*/

vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    
    vector<vector<int>> res;
    //vector<int> res1;
    int hd = 0;
    
    if(!A)
    return res;
    
    map < int,vector<int> > M; 
    
    queue<pair<TreeNode*, int> > Q; 
    Q.push(make_pair(A, hd));
    
    while(!Q.empty())
    {
        pair<TreeNode*,int> temp = Q.front(); 
        Q.pop(); 
        hd = temp.second; 
        TreeNode* node = temp.first; 
        
        M[hd].push_back(node->val);
        
        if (node->left != NULL) 
            Q.push(make_pair(node->left, hd-1)); 
        if (node->right != NULL) 
            Q.push(make_pair(node->right, hd+1)); 
    }
    
    for (auto it=M.begin(); it!=M.end(); ++it) 
    
        //for (int i=0; i<it->second.size(); ++i) 
            //res1.push_back(it->second[i]); 
        res.push_back(it->second);
        //res1.clear();
    
    
    return res;
} 
    
