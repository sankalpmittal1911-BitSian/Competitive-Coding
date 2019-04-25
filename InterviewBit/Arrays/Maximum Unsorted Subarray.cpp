/*You are given an array (zero indexed) of N non-negative integers, A0, A1 ,…, AN-1.
Find the minimum sub array Al, Al+1 ,…, Ar so if we sort(in ascending order) that sub array, then the whole array should get sorted.
If A is already sorted, output -1.

Example :

Input 1:

A = [1, 3, 2, 4, 5]

Return: [1, 2]

Input 2:

A = [1, 2, 3, 4, 5]

Return: [-1]
In the above example(Input 1), if we sort the subarray A1, A2, then whole array A should get sorted.*/


vector<int> Solution::subUnsort(vector<int> &A) {
    
    vector<int> res;
    int maxIndex=-1;
        int minIndex=-1;

        int max = INT_MIN;
        int min = INT_MAX;

        for (int i=0; i<A.size(); i++) { 
            if (max>A[i])
                maxIndex = i;
            else{
                max = A[i];
            }
        }
        
        if(maxIndex==-1){
        res.push_back(-1);
        return res;
    }

        for (int i=A.size()-1; i>=0; i--) { 
            if (min<A[i])
                minIndex = i;
            else
                min = A[i];
        }
        
        
        
        
           res.push_back(minIndex);
           res.push_back(maxIndex);
        
        
        return res;
        
}
