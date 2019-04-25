/*Given numRows, generate the first numRows of Pascal’s triangle.

Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:

Given numRows = 5,

Return

[
     [1],
     [1,1],
     [1,2,1],
     [1,3,3,1],
     [1,4,6,4,1]
]*/

vector<vector<int> > Solution::generate(int A) {
    vector<vector<int> >X(A, vector<int>(A, 0));
    int i=0,j=0;
    for(i = 0; i < A; i++) 
    X[i].resize(i+1);
    
    if(A==1)
    {
        
        X[0][0]=1;
        return X;
    }
    else if(A==2)
    {
        X[0][0]=1;
    X[1][0]=1;
    X[1][1]=1;
    return X;
    }
    else
    {
    for(i=0;i<A;++i)
    {
        X[i][0]=1;
        X[i][i]=1;
    }
    for(i=2;i<A;++i)
    {
        for(j=1;j<=i-1;++j)
        {
            X[i][j]=X[i-1][j-1]+X[i-1][j];
        }
    }
    return X;
    }
}
