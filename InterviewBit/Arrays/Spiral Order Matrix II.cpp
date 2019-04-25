/*Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Given n = 3,

You should return the following matrix:

[
  [ 1, 2, 3 ],
  [ 8, 9, 4 ],
  [ 7, 6, 5 ]
]*/


vector<vector<int> > Solution::generateMatrix(int A) {
   vector<vector<int> >sol(A, vector<int>(A, 0));;
    int i, k = 0, l = 0,z=-1,num=0,n=A,m=A;
    while (k < m && l < n)
    {
        for (i = l; i < n; ++i)
        {
          X[k][i]=++num;;
        }
        k++;
 
        
        for (i = k; i < m; ++i)
        {
             X[i][n-1]=++num;;
        }
        n--;
 
        
        if ( k < m)
        {
            for (i = n-1; i >= l; --i)
            {
                X[m-1][i]=++num;
            }
            m--;
        }
 
        
        if (l < n)
        {
            for (i = m-1; i >= k; --i)
            {
                X[i][l]=++num;
            }
            l++;    
        }        
        
    }
    return X;
}
