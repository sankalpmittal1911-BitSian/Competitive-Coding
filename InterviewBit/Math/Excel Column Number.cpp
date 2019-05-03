/*Given a column title as appears in an Excel sheet, return its corresponding column number.

Example:

    A -> 1
    
    B -> 2
    
    C -> 3
    
    ...
    
    Z -> 26
    
    AA -> 27
    
    AB -> 28*/
    
    int Solution::titleToNumber(string A) {
    
    int l=A.length();
    int col_num=0;
    for(int i=0;i<l;++i)
    {
        col_num=col_num+(pow(26,l-i)*(A[i]-'A'+1));
    }
    
    return col_num;
}
