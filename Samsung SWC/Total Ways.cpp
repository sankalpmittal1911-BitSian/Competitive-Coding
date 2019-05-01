/*Now somebody has placed several obstacles in random positions on the grid, through which the robot cannot pass. Given the positions of the blocked cells, your task is to count the number of paths that the robot can take to move from (1, 1) to (M, N).

Since the answer can get very large, output the answer modulo 1000000007.
Input

The first line contains 3 integers M, N and P denoting the number of rows, number of columns and number of blocked cells respectively.
In the next P lines, each line has exactly 2 integers i and j denoting that the cell (i, j) is blocked.
Output

Output should contain a single integer, the number of paths modulo 1000000007.
Constraints

    1 <= M, N <= 103
    0 <= P <= M * N
    0 <= i < M
    0 <= j < N

Example

Input
4 3 2
3 3
3 1

Output
2*/

#include <iostream>
using namespace std;
#define mod 1000000007

int blx[100],bly[100];
int m,n,p;

bool blocked(int x, int y)
{
    for(int i=0; i<p;++i)
    {
        if(x==blx[i] && y==bly[i])
            return true;
    }

    return false;

}

int main()
{
	cin>>m>>n>>p;

	int dp[m][n];

	for(int i=0;i<m;++i)
        for(int j=0;j<n;++j)
        dp[i][j]=0;

	for(int i=0;i<p;++i)
    {
        cin>>blx[i]>>bly[i];
        //dp[blx[i]][bly[i]] = 0;
    }



    // To reach any cell of first row

    for(int i=0;i<n;++i)
    {
        if(blocked(0,i))
            break;

        dp[0][i]=1;
    }

    for(int i=0;i<m;++i)
    {
        if(blocked(i,0))
            break;

        dp[i][0]=1;
    }


    for(int i=1;i<m;++i)
    {
        for(int j=1;j<n;++j)
        {
            if(blocked(i,j))
                continue;

            if(blocked(i-1,j) && blocked(i,j-1))
                continue;

            if(!blocked(i,j-1) && !blocked(i-1,j))
                dp[i][j]=dp[i-1][j] + dp[i][j-1];
            else if(blocked(i-1,j) && !blocked(i,j-1))
                dp[i][j]=dp[i][j-1];
            else if(!blocked(i-1,j) && blocked(i,j-1))
                dp[i][j]=dp[i-1][j];

            dp[i][j] = dp[i][j]%mod;

            //cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        }
    }

    cout<<dp[m-1][n-1]%mod<<endl;

    return 0;


}
