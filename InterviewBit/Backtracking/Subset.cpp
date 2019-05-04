/*Given a set of distinct integers, S, return all possible subsets.

 Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
Also, the subsets should be sorted in ascending ( lexicographic ) order.
The list is not necessarily sorted.
Example :

If S = [1,2,3], a solution is:

[
  [],
  [1],
  [1, 2],
  [1, 2, 3],
  [1, 3],
  [2],
  [2, 3],
  [3],
]*/

void subsets_function(vector<int>& A, vector<vector<int> >& res, vector<int>& subset, int index)
{
    
    for(int i=index;i<A.size();++i)
    {
        subset.push_back(A[i]);
        res.push_back(subset);
        subsets_function(A, res, subset, i + 1); 
        subset.pop_back();
    }
    return;
}
                 
                     

vector<vector<int> > Solution::subsets(vector<int> &A) {
   
   vector<vector<int>> res;
   vector<int> subset;
   
   res.push_back(subset);
   
   int index=0;
   
   subsets_function(A,res,subset,index);
   
   for(int i=0;i<res.size();++i)
   sort(res[i].begin(),res[i].end());
   
   sort(res.begin(),res.end());
   
   return res;
   
}
