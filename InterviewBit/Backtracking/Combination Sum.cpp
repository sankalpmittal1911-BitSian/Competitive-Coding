/*Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

 Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The combinations themselves must be sorted in ascending order.
CombinationA > CombinationB iff (a1 > b1) OR (a1 = b1 AND a2 > b2) OR … (a1 = b1 AND a2 = b2 AND … ai = bi AND ai+1 > bi+1)
The solution set must not contain duplicate combinations.
Example, 
Given candidate set 2,3,6,7 and target 7,
A solution set is:

[2, 2, 3]
[7]
 Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING COMBINATIONS.
Example : itertools.combinations in python.
If you do, we will disqualify your submission retroactively and give you penalty points. */


void getNumbers(vector<int> &A, int B, vector<int>&comb,vector<vector<int>> &res, int index)
{
    if(B<0)
    return;
    
    if(B==0)
    {
        res.push_back(comb);
        return;
    }
    
    while(index<A.size() && B-A[index]>=0 )
    {
        comb.push_back(A[index]);
        getNumbers(A,B-A[index],comb,res,index);
        ++index;
        comb.pop_back();
    }
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    
    //First Sort A
    
    sort(A.begin(),A.end());
    
    vector <int> comb;
    vector<vector<int>> res;
    A.erase(unique(A.begin(), A.end()), A.end()); 
    getNumbers(A,B,comb,res,0);
    
    return res;
}