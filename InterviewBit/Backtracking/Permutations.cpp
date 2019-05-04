/*Given a collection of numbers, return all possible permutations.

Example:

[1,2,3] will have the following permutations:

[1,2,3]
[1,3,2]
[2,1,3] 
[2,3,1] 
[3,1,2] 
[3,2,1]
 NOTE
No two entries in the permutation sequence should be the same.
For the purpose of this problem, assume that all the numbers in the collection are unique.
 Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING PERMUTATIONS.
Example : next_permutations in C++ / itertools.permutations in python.
If you do, we will disqualify your submission retroactively and give you penalty points. */

void permute(vector<int> &A, int l, int r, vector<vector<int>> &res) 
{ 
   int i; int temp=0;
   if (l == r) 
     {
        res.push_back(A);
        return;
     }
   else
   { 
       for (i = l; i <= r; i++) 
       { 
         swap(A[l],A[i]);
          permute(A, l+1, r,res); 
          swap(A[l],A[i]);
       } 
   } 
} 




vector<vector<int> > Solution::permute(vector<int> &A) {
    
    vector<vector<int>> res;
    int n=A.size();
    
    permute(A,0,n-1,res);
    return res;
}
