/*The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3 ) :

1. "123"
2. "132"
3. "213"
4. "231"
5. "312"
6. "321"
Given n and k, return the kth permutation sequence.

For example, given n = 3, k = 4, ans = "231"

 Good questions to ask the interviewer :
What if n is greater than 10. How should multiple digit numbers be represented in string?
 In this case, just concatenate the number to the answer.
so if n = 11, k = 1, ans = "1234567891011" 
Whats the maximum value of n and k?
 In this case, k will be a positive integer thats less than INT_MAX.
n is reasonable enough to make sure the answer does not bloat up a lot.*/

int factorial(int n) {
        if (n > 12) {
            
            return INT_MAX;
        }
       
        int fact = 1;
        for (int i = 2; i <= n; i++) fact *= i;
        return fact;
    }

    string getPermutation(int k, vector<int> &candidateSet) {
        int n = candidateSet.size();
        if (n == 0) {
        return "";
        }
        if (k > factorial(n)) return ""; 

        int f = factorial(n - 1);
        int pos = k / f;
        k %= f;
        string ch = to_string(candidateSet[pos]);
        
        candidateSet.erase(candidateSet.begin() + pos);
        return ch + getPermutation(k, candidateSet);
    }

string Solution::getPermutation(int A, int B) {
    
    vector<int> candidateSet; 
        for (int i = 1; i <= n; i++) candidateSet.push_back(i);
        return getPermutation(A - 1, candidateSet);
}
