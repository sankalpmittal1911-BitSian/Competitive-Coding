//I could not solve this by myself

/*Max Heap is a special kind of complete binary tree in which for every node the value present in that node is greater than the value present in it’s children nodes. If you want to know more about Heaps, please visit this link

So now the problem statement for this question is:

How many distinct Max Heap can be made from n distinct integers

In short, you have to ensure the following properties for the max heap :

Heap has to be a complete binary tree ( A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible. )
Every node is greater than all its children
Let us take an example of 4 distinct integers. Without loss of generality let us take 1 2 3 4 as our 4 distinct integers

Following are the possible max heaps from these 4 numbers :

         4 
       /  \ 
      3   2 
     / 
    1
         4 
       /  \ 
      2   3 
     / 
    1
        4 
       /  \ 
      3   1 
     / 
    2
These are the only possible 3 distinct max heaps possible for 4 distinct elements.

Implement the below function to return the number of distinct Max Heaps that is possible from n distinct elements.

As the final answer can be very large output your answer modulo 1000000007

Input Constraints : n <= 100

 NOTE: Note that even though constraints are mentioned for this problem, for most problems on InterviewBit, constraints are intentionally left out. In real interviews, the interviewer might not disclose constraints and ask you to do the best you can do. */
 

int closest(int n){
    long long int m = 0;
    long long int s = 1;
    while(n != 1){
        n = n / 2;
        m++;
    }
    return m;
}
long long int combination(int n,int r,int mod){
    int C[r+1];
    memset(C, 0, sizeof(C));
 
    C[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = min(i, r); j > 0; j--)
            C[j] = (C[j] + C[j-1])%mod;
    }
    return C[r];
}
int Solution::solve(int A) {
    if(A == 0){
        return 1;
    }
    else if(A == 1){
        return 1;
    }
    else{
        int k = closest(A);
        int M = 1 + A - pow(2,k);
        int p = pow(2,k-1);
        int l = p - 1 + min(p,M);
        int r = p - 1 + max(0,M-p);
        long long int x = combination(A-1,l,1000000007);
        long long int y = solve(l);
        long long int z = solve(r);
        return (((x*y) % 1000000007)* z) % 1000000007;
    }
}
