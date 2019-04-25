/*Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].

If there is no solution possible, return -1.

Example :

A : [3 5 4 2]

Output : 2 
for the pair (3, 4)
*/

int Solution::maximumGap(const vector<int> &A) {
    int maxDiff;
    int i, j;
    int n=A.size();
 
    int *LMin = (int *)malloc(sizeof(int)*n);
    int *RMax = (int *)malloc(sizeof(int)*n);
 
  
    LMin[0] = A[0];
    for (i = 1; i < n; ++i)
        LMin[i] = min(A[i], LMin[i-1]);
 
   
    RMax[n-1] = A[n-1];
    for (j = n-2; j >= 0; --j)
        RMax[j] = max(A[j], RMax[j+1]);
 
  
    i = 0, j = 0, maxDiff = -1;
    while (j < n && i < n)
    {
        if (LMin[i] <= RMax[j])
        {
            maxDiff = max(maxDiff, j-i);
            j = j + 1;
        }
        else
            i = i+1;
    }
 
    return maxDiff;
}
