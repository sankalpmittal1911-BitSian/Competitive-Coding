/*Determine whether an integer is a palindrome. Do this without extra space.

A palindrome integer is an integer x for which reverse(x) = x where reverse(x) is x with its digit reversed.
Negative numbers are not palindromic.

Example :

Input : 12121
Output : True

Input : 123
Output : False*/

bool Solution::isPalindrome(int A) {
    if(A<0)
        return false;
    long int temp = 0, temp2 = A;
    while(A!=0)
    {
        temp = temp*10 + A%10;
        A/=10;
    }

    if(temp==temp2)
        return true;
    else
        return false;
}
