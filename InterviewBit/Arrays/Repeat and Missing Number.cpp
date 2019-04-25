/*You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Note that in your output A should precede B.

Example:

Input:[3 1 2 5 3] 

Output:[3, 4] 

A = 3, B = 4*/

typedef long long ll;
 
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    ll n=A.size();
    ll sum=0;
    ll sumsq=0;
    for(ll i=0;i<n;i++)
    {
        sum+=(ll)A[i];
        sumsq+=((ll)A[i]*(ll)A[i]);
    }
    
    ll diff = (n*(n+1)/2)-sum;
    
    ll diff2 = ((n*(n+1)*(2*n+1))/6)-sumsq;
    
    ll sumi = diff2/diff;

    int repeated = (sumi-diff)/2;
    
    int missing = (diff+sumi)/2;
  
    vector<int> ans;
    
    ans.push_back(repeated);
    ans.push_back(missing);
    
    return ans;
}
