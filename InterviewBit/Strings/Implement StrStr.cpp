/*Please Note:
Another question which belongs to the category of questions which are intentionally stated vaguely. 
Expectation is that you will ask for correct clarification or you will state your assumptions before you start coding.

Implement strStr().

 strstr - locate a substring ( needle ) in a string ( haystack ). 
Try not to use standard library string functions for this question.

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 NOTE: Good clarification questions:
What should be the return value if the needle is empty?
What if both haystack and needle are empty?
For the purpose of this problem, assume that the return value should be -1 in both cases. */

int Solution::strStr(const string A, const string B) {
    
    int i,j,flag=1;
    if(A=="" || B=="" || A.length()<B.length())
    return -1;
    for(i=0;i<=A.length()-B.length();++i)
    {
        if(i + B.length() > A.length())
            return -1;
        if(A[i]==B[0])
        {
            for(j=i;j<i+B.length();++j)
            {
                if(A[j]!=B[j-i])
                {
                    flag=0;
                    break;
                }
            }
            if(flag==1)
            return i;
           
        }
        
        flag=1;
         
        
    }
    return -1;
}
