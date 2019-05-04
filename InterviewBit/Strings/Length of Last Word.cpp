/*Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Given s = "Hello World",

return 5 as length("World") = 5.

Please make sure you try to solve this problem without using library functions. Make sure you only traverse the string once.*/

int Solution::lengthOfLastWord(const string A) {
    if(A=="")
    return 0;
    string s=" "+A;
    int i,p=s.length()-1;
    for(i=s.length()-1;i>=0;--i)
    {
        if(s[i]==' ')
        p=i-1;
        if(s[i-1]==' ' && s[i]!=' ')
        return p-i+1;
    }
    return 0;
}
