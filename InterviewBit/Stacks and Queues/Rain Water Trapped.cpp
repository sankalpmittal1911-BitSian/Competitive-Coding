/*Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

Example :

Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

Rain water trapped: Example 1

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
In this case, 6 units of rain water (blue section) are being trapped.*/

int Solution::trap(const vector<int> &A) {
    
    int n=A.size(),water=0;
    
    vector <int> left(n);
    vector <int> right(n);
    
    left[0]=A[0];
    right[n-1]=A[n-1];
    
    for(int i=1;i<n;++i)
    {
        left[i]=max(left[i-1],A[i]);
        right[n-i-1]=max(right[n-i],A[n-i-1]);
    }
    
    for (int i = 0; i < n; i++) 
       water += min(left[i],right[i]) - A[i]; 
  
    return water; 
}
