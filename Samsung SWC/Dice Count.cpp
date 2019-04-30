/*Given n dice each with 6 faces, numbered from 1 to 6, find the number of ways to get sum X. X is the summation of values on each face when all the dice are thrown.

Example: If n = 3, X = 6, number of possible ways are : 10

1 1 4 = 6
1 2 3 = 6
1 3 2 = 6
1 4 1 = 6
2 1 3 = 6
2 2 2 = 6
2 3 1 = 6
3 1 2 = 6
3 2 1 = 6
4 1 1 = 6

Other Input Example:
6    ; Number of test cases
3 6 ; n and X value
2 1
2 3
3 8
2 5
3 5

Output:
10
0
2
21
4
6*/


#include<iostream>

using namespace std;

int c;

bool isSafe(int sum, int cra, int n)
{
    if(sum<0 || cra > n)
        return false;

    return true;
}

void count_ways(int n, int X, int cra)
{
    if(isSafe(X,cra,n))
    {
        if(X==0 && cra==n)
        {
            ++c;
            return;
        }

            for(int j=1;j<=6;++j)
                count_ways(n,X-j,cra+1);
        }

        return;
    }

int main()
{
    int X,n;

    cin>>n;

    cin>>X;

    c=0;

    count_ways(n,X,0);

    cout<<c<<endl;

    return 0;

}


//Can you write DP solution?

//Hint:

int main()
{
    int n,X;

    cin>>n>>X;

    int dp[n+1][X+1];

    for(int i=0;i<=n;++i)
        for(int j=0;j<=X;++j)
        dp[i][j]=0;

    for(int i=1;i<=6 && i<=X;++i)
        dp[1][i] = 1;

    for(int i=2;i<=n;++i)
    {
        for(int j=1;j<=X;++j)
        {
            for(int k = 1; k<=6 && k<=X;++k)
            {
                dp[i][j]+=dp[i-1][j-k];
            }
        }
    }

    cout<<dp[n][X]<<endl;

    return 0;
}

