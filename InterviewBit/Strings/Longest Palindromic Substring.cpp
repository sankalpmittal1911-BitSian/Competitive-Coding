/*Given a string S, find the longest palindromic substring in S.

Substring of string S:

S[i...j] where 0 <= i <= j < len(S)

Palindrome string:

A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S.

Incase of conflict, return the substring which occurs first ( with the least starting index ).

Example :

Input : "aaaabaaa"
Output : "aaabaaa"*/

string Solution::longestPalindrome(string A) {
    
    int i,j,l,r;
    string longest_substr=A.substr(0,1),substr="";
    for(i=0;i<A.length()-1;++i)
    {
        l=i;r=i;
        while(l>=0 && r<=A.length()-1 && A[l]==A[r])
        {
            l--;
            r++;
        }
        substr=A.substr(l+1,r-l-1);
        if(substr.length()>longest_substr.length())
        longest_substr=""+substr;
        l=i;r=i+1;
        while(l>=0 && r<=A.length()-1 && A[l]==A[r])
        {
            l--;
            r++;
        }
        substr=A.substr(l+1,r-l-1);
        if(substr.length()>longest_substr.length())
        longest_substr=""+substr;
    }
    return longest_substr;
}
