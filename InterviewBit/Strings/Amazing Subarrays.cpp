/*You are given a string S, and you have to find all the amazing substrings of S.

Amazing Substring is one that starts with a vowel (a, e, i, o, u, A, E, I, O, U).

Input

Only argument given is string S.
Output

Return a single integer X mod 10003, here X is number of Amazing Substrings in given string.
Constraints

1 <= length(S) <= 1e6
S can have special characters
Example

Input
    ABEC

Output
    6

Explanation
	Amazing substrings of given string are :
	1. A
	2. AB
	3. ABE
	4. ABEC
	5. E
	6. EC
	here number of substrings are 6 and 6 % 10003 = 6.*/
  
  int Solution::solve(string A) {
    
    int n=A.length();
    int c=0;
    
    
        for(int i=0;i<n;++i)
        {
            switch(A[0])
            {
                case 'a':
                c=c+(n-i)%10003;;
                c%=10003;
                break;
                
                case 'e':
                c=c+n-i;
                c%=10003;
                break;
                
                case 'i':
                c=c+n-i;
                c%=10003;
                break;
                
                case 'o':
                c=c+n-i;
                c%=10003;
                break;
                
                case 'u':
                c=c+n-i;
                c%=10003;
                break;
                
                case 'A':
                c=c+n-i;
                c%=10003;
                break;
                
                case 'E':
                c=c+n-i;
                c%=10003;
                break;
                
                case 'I':
                c=c+n-i;
                c%=10003;
                break;
                
                case 'O':
                c=c+n-i;
                c%=10003;
                break;
                
                case 'U':
               c=c+n-i;
               c%=10003;
                break;
                
            }
            
            //c=c%10003;
        }
    
    return c%=10003;;
}
