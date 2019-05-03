/*Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB */
    
    string Solution::convertToTitle(int A) {
    int rem=0;
    char c=0;
    string s="";
    while(A>0)
    {
        rem=A%26;
        c=(char)('A'+rem-1);
        s=c+s;
        A/=26;
    }
    return s;
}
