/*Given 2 non negative integers m and n, find gcd(m, n)

GCD of 2 integers m and n is defined as the greatest integer g such that g is a divisor of both m and n.
Both m and n fit in a 32 bit signed integer.

Example

m : 6
n : 9

GCD(m, n) : 3 */

int Solution::gcd(int A, int B) {
    int temp=0;
    if(A<=B)
    temp=A;
    else
    temp=B;
    if(A==0)
    return B;
    if(B==0)
    return A;
    if(A==B)
    return A;
    for(int i=temp;i>=1;--i)
    {
        if(A%i==0 && B%i==0)
        return i;
    }
}
