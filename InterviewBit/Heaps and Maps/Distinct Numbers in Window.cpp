/*You are given an array of N integers, A1, A2 ,…, AN and an integer K. Return the of count of distinct numbers in all windows of size K.

Formally, return an array of size N-K+1 where i’th element in this array contains number of distinct elements in sequence Ai, Ai+1 ,…, Ai+k-1.

Note:

If K > N, return empty array.
For example,

A=[1, 2, 1, 3, 4, 3] and K = 3

All windows of size K are

[1, 2, 1]
[2, 1, 3]
[1, 3, 4]
[3, 4, 3]

So, we return an array [2, 3, 3, 2].*/

vector<int> Solution::dNums(vector<int> &A, int B) {
    
   int ans=0;vector <int> res;
   
   if(B>A.size())
   return res;
   
    unordered_map<int,int> m;
    for(int i=0;i<A.size();i++){
        if(m.count(A[i])==0){
            m[A[i]] = i;
            ans++;
        }
       else{
           m[A[i]]=i;
       }
       if(i>=B-1){
           res.push_back(ans);
           if(m[A[i-B+1]]==i-B+1){ ans--;
           m.erase(A[i-B+1]);}
       }
    }
    return res;
}
