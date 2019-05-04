/*Please Note:
Another question which belongs to the category of questions which are intentionally stated vaguely. 
Expectation is that you will ask for correct clarification or you will state your assumptions before you start coding.

Given an integer, convert it to a roman numeral, and return a string corresponding to its roman numeral version

Input is guaranteed to be within the range from 1 to 3999.

Example :

Input : 5
Return : "V"

Input : 14
Return : "XIV"
 Note : This question has a lot of scope of clarification from the interviewer. Please take a moment to think of all the needed clarifications and see the expected response using “See Expected Output” For the purpose of this question, https://projecteuler.net/about=roman_numerals has very detailed explanations. */
 
 string Solution::intToRoman(int A) {
    
    string m[] = {"", "M", "MM", "MMM"}; 
     string c[] = {"", "C", "CC", "CCC", "CD", "D",  
                        "DC", "DCC", "DCCC", "CM"}; 
     string x[] = {"", "X", "XX", "XXX", "XL", "L",  
                        "LX", "LXX", "LXXX", "XC"}; 
     string i[] = {"", "I", "II", "III", "IV", "V",  
                        "VI", "VII", "VIII", "IX"}; 
                        
                        string thousands = m[A/1000]; 
     string hundereds = c[(A%1000)/100]; 
     string tens =  x[(A%100)/10]; 
     string ones = i[A%10]; 
          
     string ans = thousands + hundereds + tens + ones; 
          
     return ans; 
}
