/*Find the largest continuous sequence in a array which sums to zero.

Example:


Input:  {1 ,2 ,-2 ,4 ,-4}
Output: {2 ,-2 ,4 ,-4}

 NOTE : If there are multiple correct answers, return the sequence which occurs first in the array. */
 
 vector<int> Solution::lszero(vector<int> &A) {
    
    int l=A.size();
    int sum=0;
    int max_len=0;
    int start=0;
    unordered_map<int,int>M;
    vector<int> res;
    
    
    for(int i=0;i<l;++i)
    {
        sum+=A[i];
        
        if(A[i]==0)
        max_len=1;
        
        if(sum==0)
        max_len=i+1;
        
        if(M.find(sum)!=M.end())
        {
            if(max_len<i-M[sum])
            {
            max_len=i-M[sum];
            start=M[sum]+1;
            }
            
        }
        else
        M[sum]=i;
       
        
    }
    
    //cout<<max_len;
    
    for(int i=start;i<start+max_len+1;++i)
    res.push_back(A[i]);
    
    return res;
}
