/*Find maximum sum by picking elements from array such that no two consecutive elements are picked.
Example: 
1) {5,1,1,4}
Resule: 9 considering 5 and 4
2) {1,2,3,4,5}
Result: 9 considering 1,3 and 5
*/

#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    fstream myfile;

    myfile.open("Input.txt");

    int t;

    myfile>>t;

    while(t--)
    {
        int n;

        myfile>>n;

        int a[n];

        for(int i=0;i<n;++i)
            myfile>>a[i];

        int dp[n+1];

        for(int i=0;i<=n;++i)
            dp[i]=0;

        dp[0]=0;
        dp[1]=a[0];
        dp[2]=max(a[0],a[1]);

        for(int i=3;i<=n;++i)
        {
            dp[i]=max(dp[i-1], a[i-1] + dp[i-2]);
        }

        cout<<dp[n]<<endl;

    }

    myfile.close();

    return 0;
}
