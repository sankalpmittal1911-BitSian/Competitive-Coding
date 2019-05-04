/*Write a program to validate if the input string has redundant braces?
Return 0/1

0 -> NO
1 -> YES
Input will be always a valid expression

and operators allowed are only + , * , - , /

Example:

((a + b)) has redundant braces so answer will be 1
(a + (a + b)) doesn't have have any redundant braces so answer will be 0*/

int Solution::braces(string A) {
    
    stack <char> S;
    int flag=0;
    
    for(int i=0;i<A.length();++i)
    {
        if(A[i]!=')')
        S.push(A[i]);
        else
        {
           if(S.top()=='(')
           return 1;
           while(!S.empty() && S.top()!='(')
           {
               if (S.top() == '+' || S.top() == '-' ||  
                    S.top() == '*' || S.top() == '/') 
                    flag=1;
                    S.pop();
                    if(S.top()=='(')
                    {
                        S.pop();
                        break;
                    }
           }
            if(flag==0)
        return 1;
        
        flag=0;
        }
        
       
        
    }
    
    return 0;
}
