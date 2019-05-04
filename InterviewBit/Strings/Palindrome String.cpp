/*Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Example:

"A man, a plan, a canal: Panama" is a palindrome.

"race a car" is not a palindrome.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem*/

int Solution::isPalindrome(string A) {
    

    int l=0, r=A.length()-1;
    
    while(l<r)
    {
       while(!isalnum(A[l]) && l<r)
       ++l;
       
       while(!isalnum(A[r]) && l<r)
       --r;
       
       if(tolower(A[l++])!=tolower(A[r--]))
       return 0;
        
    }
   
    
    return 1;
}
