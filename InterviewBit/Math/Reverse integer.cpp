/*Reverse digits of an integer.

Example1:

x = 123,

return 321
Example2:

x = -123,

return -321

Return 0 if the result overflows and does not fit in a 32 bit signed integer*/

int Solution::reverse(int A) {
    
    int negativeFlag = 0; 
    if (A < 0) 
    { 
        negativeFlag = 1; 
        A = -A ; 
    } 
  
    int prev_rev_num = 0, rev_num = 0; 
    while (A != 0) 
    { 
        int curr_digit = A%10; 
  
        rev_num = (rev_num*10) + curr_digit; 
  
      
        if ((rev_num - curr_digit)/10 != prev_rev_num) 
        { 
            return 0; 
        } 
  
        prev_rev_num = rev_num; 
        A = A/10; 
    } 
  
    return (negativeFlag == 1)? -rev_num : rev_num; 
}
