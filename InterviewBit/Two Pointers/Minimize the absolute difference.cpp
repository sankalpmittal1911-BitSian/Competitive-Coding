/*Given three sorted arrays A, B and Cof not necessarily same sizes.

Calculate the minimum absolute difference between the maximum and minimum number from the triplet a, b, c such that a, b, c belongs arrays A, B, C respectively.
i.e. minimize | max(a,b,c) - min(a,b,c) |.

Example :

Input:

A : [ 1, 4, 5, 8, 10 ]
B : [ 6, 9, 15 ]
C : [ 2, 3, 6, 6 ]
Output:

1
Explanation: We get the minimum difference for a=5, b=6, c=6 as | max(a,b,c) - min(a,b,c) | = |6-5| = 1.*/

int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    
    int i=A.size()-1,j=B.size()-1,k=C.size()-1;
            int min_diff, current_diff, max_term; 

   
        min_diff = abs(max(A[i], max(B[j], C[k]))  
                     - min(A[i], min(B[j], C[k]))); 
  
        while (i != -1 && j != -1 && k != -1)  
        { 
            current_diff = abs(max(A[i], max(B[j], C[k]))  
                            - min(A[i], min(B[j], C[k]))); 
  
            
            if (current_diff < min_diff) 
                min_diff = current_diff; 
  
            // calculating max term from list 
            max_term = max(A[i], max(B[j], C[k])); 
  
            
            if (A[i] == max_term) 
                i -= 1; 
            else if (B[j] == max_term) 
                j -= 1; 
            else
                k -= 1; 
        } 
          
        return min_diff; 
}
