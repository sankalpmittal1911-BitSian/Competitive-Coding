/*Max Sum Contiguous Subarray
Asked in:  
Facebook
Paypal
Yahoo
Microsoft
LinkedIn
Amazon
Goldman Sachs
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example:

Given the array [-2,1,-3,4,-1,2,1,-5,4],

the contiguous subarray [4,-1,2,1] has the largest sum = 6.

For this problem, return the maximum sum.*/

int Solution::maxSubArray(const vector<int> &A) {
    int ans=A[0],i,j,sum=0;
        for(i=0;i<A.size();++i){
            sum+=A[i];
            ans=max(sum,ans);
            sum=max(sum,0);
}
return ans;
}
