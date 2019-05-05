/*Given two arrays A & B of size N each.
Find the maximum n elements from the sum combinations (Ai + Bj) formed from elements in array A and B.

For example if A = [1,2], B = [3,4], then possible pair sums can be 1+3 = 4 , 1+4=5 , 2+3=5 , 2+4=6
and maximum 2 elements are 6, 5

Example:

N = 4
a[]={1,4,2,3}
b[]={2,5,1,6}

Maximum 4 elements of combinations sum are
10   (4+6), 
9    (3+6),
9    (4+5),
8    (2+6)*/

#include<bits/stdc++.h>

using namespace std;

vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    
    sort(A.begin(),A.end(), greater<int>());
    sort(B.begin(),B.end(), greater<int>());
    int N=A.size();
    
    vector<int> res;
    
    priority_queue <pair<int,pair<int,int>>> pq;
    
    set <pair<int,int>> S;
    
    pq.push(make_pair(A[0]+B[0],make_pair(0,0)));
    S.insert(make_pair(0,0));
    
    while(N--)
    {
        pair<int,pair<int,int>> p = pq.top();
        
        res.push_back(p.first);
        
        pq.pop();
        
        //make two pairs
        
        int i = p.second.first;
        int j = p.second.second;
        
        int sum1= A[i+1]+B[j];
        int sum2=A[i]+B[j+1];
        
        if(S.find(make_pair(i+1,j))==S.end())
        {
            pq.push({sum1,{i+1,j}});
            S.insert({i+1,j});
        }
        
        if(S.find(make_pair(i,j+1))==S.end())
        {
            pq.push({sum2,{i,j+1}});
            S.insert({i,j+1});
        }
        
        
        
    }
    
    return res;
    
    
}
