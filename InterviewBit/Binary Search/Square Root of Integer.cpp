/*Implement int sqrt(int x).

Compute and return the square root of x.

If x is not a perfect square, return floor(sqrt(x))

Example :

Input : 11
Output : 3*/


int Solution::sqrt(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
     if (A == 0 || A == 1)  
       return A; 
  if(A==2)
  return 1;
    // Do Binary Search for floor(sqrt(x)) 
    int start = 1, end = A, ans;    
    while (start <= end)  
    {         
        int mid = (start ) + (end-start)/ 2; 
  
        // If x is a perfect square 
        if (mid == A/mid) 
            return mid; 
  
        // Since we need floor, we update answer when mid*mid is  
        // smaller than x, and move closer to sqrt(x) 
        if (mid < A/mid)  
        { 
            start = mid + 1; 
            ans = mid; 
        }  
        else // If mid*mid is greater than x 
            {
            end = mid-1;
            //ans=mid;
            }
    } 
    return ans; 
    
    
}
