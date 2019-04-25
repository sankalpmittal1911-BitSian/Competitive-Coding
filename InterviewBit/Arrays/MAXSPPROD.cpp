/*You are given an array A containing N integers. The special product of each ith integer in this array is defined as the product of the following:<ul>

LeftSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] (i>j). If multiple A[j]’s are present in multiple positions, the LeftSpecialValue is the maximum value of j. 

RightSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] (j>i). If multiple A[j]s are present in multiple positions, the RightSpecialValue is the minimum value of j.

Write a program to find the maximum special product of any integer in the array.

Input: You will receive array of integers as argument to function.

Return: Maximum special product of any integer in the array modulo 1000000007.

Note: If j does not exist, the LeftSpecialValue and RightSpecialValue are considered to be 0.

Constraints 1 <= N <= 10^5 1 <= A[i] <= 10^9*/

int Solution::maxSpecialProduct(vector<int> &A) {
    
    int n=A.size();
int B[n],C[n];
stack<pair<long long int ,int> > S;
pair<int ,int > p;
p=make_pair(INT_MAX,0);
S.push(p);
for(int i=0;i<n;i++)
{while(A[i]>=S.top().first)
S.pop();
B[i]=S.top().second;
p=make_pair(A[i],i);
S.push(p);
}
while(!S.empty())
S.pop();
p=make_pair(INT_MAX,0);
S.push(p);
for(int i=n-1;i>=0;i--)
{while(A[i]>=S.top().first)
S.pop();
C[i]=S.top().second;
p=make_pair(A[i],i);
S.push(p);
}
long long int x=B[0],y=C[0],m;
m=x*y;
for(int i=0;i<n;i++)
{x=B[i];y=C[i];
m=max(m,x*y);
}
return m%1000000007;

  
}
