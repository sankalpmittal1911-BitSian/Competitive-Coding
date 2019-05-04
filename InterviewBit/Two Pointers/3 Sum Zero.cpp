/*Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note:

 Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets. For example, given array S = {-1 0 1 2 -1 -4}, A solution set is:
(-1, 0, 1)
(-1, -1, 2) */

vector<vector<int> > Solution::threeSum(vector<int> &A) {
    
    
    bool found = false; 
    vector <int> temp;
    vector <vector <int>> result;
  
    // sort array elements 
    sort(A.begin(), A.end()); 
  
    for (int i=0; i<A.size()-1; i++) 
    { 
        // initialize left and right 
        int l = i + 1; 
        int r = A.size() - 1; 
        int x = A[i]; 
        while (l < r) 
        { 
            if (x + A[l] + A[r] == 0) 
            { 
                // print elements if it's sum is zero 
                //printf("%d %d %d\n", x, A[l], A[r]); 
                temp.push_back(x);
                temp.push_back(A[l]);
                temp.push_back(A[r]);
                result.push_back(temp);
                temp.clear();
                l++; 
                r--; 
                found = true; 
            } 
  
            // If sum of three elements is less 
            // than zero then increment in left 
            else if (x + A[l] + A[r] < 0) 
                l++; 
  
            // if sum is greater than zero than 
            // decrement in right side 
            else
                r--; 
        } 
    } 
  
    return result;
}
