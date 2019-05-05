/*Given an array of integers, find the length of longest subsequence which is first increasing then decreasing.

**Example: **

For the given array [1 11 2 10 4 5 2 1]

Longest subsequence is [1 2 10 4 2 1]

Return value 6*/

int Solution::longestSubsequenceLength(const vector<int> &A) {
    
    vector <int> Lis(A.size(),1);
    vector <int> Lds(A.size(),1);
    
    if(A.size()==0)
    return 0;
    
    for(int i=1;i<A.size();++i)
    {
        for(int j=0;j<i;++j)
        {
            if(A[i]>A[j] && Lis[i]<Lis[j]+1)
            Lis[i]=Lis[j]+1;
        }
    }
    
    for(int i=A.size()-2;i>=0;--i)
    {
        for(int j=A.size()-1;j>i;--j)
        {
            if(A[i]>A[j] && Lds[i]<Lds[j]+1)
            Lds[i]=Lds[j]+1;
        }
    }
    
    int max_Ls=Lis[0]+Lds[0]-1;
    
    for(int i=1;i<A.size();++i)
    {
        if(Lis[i]+Lds[i]-1>=max_Ls)
        max_Ls=Lis[i]+Lds[i]-1;
    }
    
    return max_Ls;
}
