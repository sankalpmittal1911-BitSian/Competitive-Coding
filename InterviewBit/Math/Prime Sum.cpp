/*Given an even number ( greater than 2 ), return two prime numbers whose sum will be equal to given number.

NOTE A solution will always exist. read Goldbach’s conjecture

Example:


Input : 4
Output: 2 + 2 = 4

If there are more than one solutions possible, return the lexicographically smaller solution.

If [a, b] is one solution with a <= b,
and [c,d] is another solution with c <= d, then

[a, b] < [c, d] 

If a < c OR a==c AND b < d. */

bool isPrime(int n)
{
    for(int i=2; i*i<=n; ++i)
    {
        if(n%i==0)
            return false;
    }
    return true;
}

vector<int> Solution::primesum(int A) {
    vector<int> result;
    if(A<3)
        return result;
    vector<bool> arr(A+1, 0); //vector<int> causes judge memory overflow.
    
    for (int i=2; i<=A; ++i)
    {
        if(arr[i]==0)
        {
            //prime.emplace_back(i);
            if(isPrime(A-i))
            {
                result.emplace_back(i);
                result.emplace_back(A-i);
                break;
            }
            for(int j=i; i*j<=A; ++j)
                arr[i*j] = 1;
        }   
    }
    return result;
}
