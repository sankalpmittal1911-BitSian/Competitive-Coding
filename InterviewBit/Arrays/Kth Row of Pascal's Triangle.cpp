/*Given an index k, return the kth row of the Pascal’s triangle.

Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:

Input : k = 3

Return : [1,3,3,1]
 NOTE : k is 0 based. k = 0, corresponds to the row [1]. 
Note:Could you optimize your algorithm to use only O(k) extra space?*/

vector<int> Solution::getRow(int A) {
    vector<vector<int> >X(A+1, vector<int>(A+1, 0));
    int i=0,j=0;
    for(i = 0; i <=A; i++) 
    X[i].resize(i+1);
    
    if(A==0)
    {
        
        X[0][0]=1;
        return X[0];
    }
    else if(A==1)
    {
        X[0][0]=1;
    X[1][0]=1;
    X[1][1]=1;
    return X[1];
    }
    else
    {
    for(i=0;i<=A;++i)
    {
        X[i][0]=1;
        X[i][i]=1;
    }
    for(i=2;i<=A;++i)
    {
        for(j=1;j<=i-1;++j)
        {
            X[i][j]=X[i-1][j-1]+X[i-1][j];
        }
    }
    return X[A];
    }
}
