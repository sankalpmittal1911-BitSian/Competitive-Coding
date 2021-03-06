/*Asked in:  
Oracle
Amazon
Given an m x n matrix of 0s and 1s, if an element is 0, set its entire row and column to 0.

Do it in place.

Example

Given array A as

1 0 1
1 1 1 
1 1 1
On returning, the array A should be :

0 0 0
1 0 1
1 0 1
Note that this will be evaluated on the extra memory used. Try to minimize the space and time complexity.*/

void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

   int rows[A.size()];
   int cols[A[0].size()];
   
   memset(rows,0,sizeof rows);
   memset(cols,0,sizeof cols);
   
   for(int i=0;i<A.size();++i)
   {
       for(int j=0;j<A[i].size();++j)
       {
           if(A[i][j]==0)
           {
               rows[i]=1;
               cols[j]=1;
           }
       }
   }
    
    
    for(int i=0;i<A.size();++i)
   {
       for(int j=0;j<A[i].size();++j)
       {
           if(rows[i]==1 || cols[j]==1)
           A[i][j]=0;
       }
   }
    
    
    
}
