/*Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details.

Example:

		
Input: 	

1 2 3
4 5 6
7 8 9

Return the following :

[ 
  [1],
  [2, 4],
  [3, 5, 7],
  [6, 8],
  [9]
]


Input : 
1 2
3 4

Return the following  : 

[
  [1],
  [2, 3],
  [4]
]*/

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    
    vector<vector<int>> result;
    vector<int> diagonal;
    
    if(A.size() == 0)
        return result;
    for(int d = 0; d <= 2*(A.size()-1); d++) 
    {
       for(int i = 0; i <= d; i++) 
       {
           int j = d - i;
           if(i >= A.size() || j >= A.size())
                continue;
           diagonal.push_back(A[i][j]);
       }
       result.push_back(diagonal);
       diagonal.clear();
   }
   return result;
}
