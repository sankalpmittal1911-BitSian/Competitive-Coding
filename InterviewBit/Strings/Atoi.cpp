/*Please Note:
There are certain questions where the interviewer would intentionally frame the question vague.
The expectation is that you will ask the correct set of clarifications or state your assumptions before you jump into coding.

Implement atoi to convert a string to an integer.

Example :

Input : "9 2704"
Output : 9
Note: There might be multiple corner cases here. Clarify all your doubts using “See Expected Output”.

 Questions: Q1. Does string contain whitespace characters before the number?
A. Yes Q2. Can the string have garbage characters after the number?
A. Yes. Ignore it. Q3. If no numeric character is found before encountering garbage characters, what should I do?
A. Return 0. Q4. What if the integer overflows?
A. Return INT_MAX if the number is positive, INT_MIN otherwise. 
Warning : DO NOT USE LIBRARY FUNCTION FOR ATOI.
If you do, we will disqualify your submission retroactively and give you penalty points.*/

int Solution::atoi(const string A) {
    
     int sign = 1, base = 0, i = 0; 
    while (A[i] == ' ') 
     {   
      i++; 
     } 
    if (A[i] == '-' || A[i] == '+') { 
        sign = 1 - 2 * (A[i++] == '-');  
    } 
  
    while (A[i] >= '0' && A[i] <= '9')  
      { 
     
        if (base >  INT_MAX / 10 || (base == INT_MAX / 10 && A[i] - '0' > 7)) { 
            if (sign == 1) return INT_MAX; 
            else return INT_MIN; 
        } 
        base  = 10 * base + (A[i++] - '0'); 
    } 
    return base * sign; 
}
