/*You are given a string. The only operation allowed is to insert characters in the beginning of the string. How many minimum characters are needed to be inserted to make the string a palindrome string

Example:
Input: ABC
Output: 2
Input: AACECAAAA
Output: 2*/

int isPalin(string s,int l,int r)
{
    while(l<r)
    {
        if(s[l++]!=s[r--])
        return 0;
    }
    
    return 1;
}


int Solution::solve(string A) {
    
    int flag=0,c=0;
    
    while(A.length())
    {
        if(isPalin(A,0,A.length()-1))
        {
            flag=1;
            break;
        }
        
        else
        {
            ++c;
            A.erase(A.begin()+A.length()-1);
        }
    }
    
    return c;
}
