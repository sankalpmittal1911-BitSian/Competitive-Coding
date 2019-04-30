/*Coin collection Game (15-June)
You are playing a game. Game has few rows and 5 columns. Each cell can have 3 values.
0 – Normal
1 – coin
2 – Enemy
    Your curser is currently at row 0, column 2 (middle). During your turn, you can move your curser to either immediate left or right location or stay where you are. Once your movement for that turn is over, based on the cell value at that row and column, you either get nothing (cell value 0), one coin (cell value 1) or enemy (cell value 2). If you get enemy, your coin count is decremented by 1. If your coin count goes below 0, you die. 
      Once a row is processed, that row disappears and you need to repeat same operation on next row. You also have a bomb. If you use it, all enemies in 5 rows starting from current row die (cell value becomes 0). There will be no change in cells with value 0 and 1 when you use bomb. Ex. You use your bomb at row 3, then all enemies from row 3,4,5,6,7 die. You can use bomb only once.
Once you complete last row, you stop. Write a program to collect as many coins as possible. Your answer is maximum number of coins that can be collected in given game.
Input:
T Total number of test cases. For each test case, N – number of rows in given game. Next N lines have 3 values (0,1 or 2).
Output:
 #<test no.><space><maximum number of coins that can be collected in given game>

Input:
6
6
2 2 2 2 2
0 0 0 0 0
0 0 2 0 0
2 0 0 0 2
0 0 0 0 0
1 2 2 2 1
7
1 2 0 0 1
2 0 0 1 0
0 1 2 0 1
1 0 0 2 1
0 2 1 0 1
0 1 2 2 2
1 0 1 1 0
10
2 2 2 2 0
1 2 0 0 2
0 2 0 0 0
2 2 0 2 2
0 2 2 2 0
0 0 0 0 0
1 0 0 0 2
0 0 0 0 0
2 2 0 2 1
0 2 2 2 0
5
1 1 0 0 0
1 2 2 2 1
1 1 2 2 1
2 2 2 1 2
2 2 0 2 0
12
2 2 0 2 2
0 1 0 2 1
0 2 0 1 0
2 1 2 1 0
0 2 2 1 2
0 1 2 2 2
0 2 1 0 2
2 0 1 1 2
2 1 1 0 1
0 2 2 0 0
2 0 1 2 2
2 2 1 2 1
8
1 2 2 2 2
2 2 0 0 0
2 0 0 0 0
0 0 0 0 0
2 2 2 2 2
2 2 2 2 1
2 2 2 2 2
2 2 1 2 2
*/

//METHOD 1

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int a[13][5],b[5][5];

int max_coins=-1;
bool bombUsed=false;

void detonate(int row)
{
    for(int i=row;i>row-5;--i)
    {
        for(int j=0;j<5;++j)
        {
            if(i>=0 && a[i][j]==2)
            {
                b[row-i][j]=2;
                a[i][j]=0;
            }
        }
    }
}

void undetonate(int row)
{
    for(int i=row;i>row-5;--i)
    {
        for(int j=0;j<5;++j)
        {
            if(i>=0 && b[row-i][j]==2)
            {
                a[i][j]=2;
                b[row-i][j]=0;
            }
        }
    }
}


bool isSafe(int row, int col, int coins)
{
    if(row<0 || col<0 || col>4 || coins<0)
        return false;
    return true;
}

void getMaxCoins(int row, int col, int coins)
{

    if (isSafe(row,col,coins))
    {

        if(bombUsed==false)
            {
                bombUsed=true;
                detonate(row-1);
            getMaxCoins(row,col,coins);
            undetonate(row-1);
            bombUsed=false;
            }


        int val=0;

        if(a[row][col]==0)
            val=0;
        else if(a[row][col]==1)
            val=1;
        else
            val=-1;

        coins+=val;

        //cout<<"row:"<<row<<" "<<"col:"<<col<<" "<<"value:"<<a[row][col]<<" "<<"coins:"<<coins<<" "<<"bombUsed:"<<bombUsed<<endl;

        if(coins<0)
            return;

        if(row==0)
            {
                if(max_coins<=coins)
                {
                    max_coins=coins;
                    //cout<<"maxCoins:"<<max_coins<<endl;
                    return;
                }
            }



        getMaxCoins(row-1,col,coins);
        getMaxCoins(row-1,col-1,coins);
        getMaxCoins(row-1,col+1,coins);

        }


    return;
}

int main()
{
    int t;

    cin>>t;

    while(t--)
    {
        max_coins=-1;
        bombUsed=false;

    int n,i,j;

    cin>>n;

    for(int i=0;i<n;++i)
        for(int j=0;j<5;++j)
        cin>>a[i][j];

    for(int i=0;i<5;++i)
        a[n][i]=0;


    getMaxCoins(n,2,0);

    if(max_coins<0)
        max_coins=-1;

    cout<<max_coins<<endl;
    }

    return 0;
}


//METHOD 2

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int a[13][5],b[5][5];

int max_coin=-1;

int ans=-1;

void detonate(int row)
{
    for(int i=row;i>row-5;--i)
    {
        for(int j=0;j<5;++j)
        {
            if(i>=0 && a[i][j]==2)
            {
                b[row-i][j]=2;
                a[i][j]=0;
            }
        }
    }
}

void undetonate(int row)
{
    for(int i=row;i>row-5;--i)
    {
        for(int j=0;j<5;++j)
        {
            if(i>=0 && b[row-i][j]==2)
            {
                a[i][j]=2;
                b[row-i][j]=0;
            }
        }
    }
}

bool isSafe(int row, int col, int coins)
{
    if(row<0 || col<0 || col>4 || coins<0)
        return false;
    return true;
}


void max_coins1(int row, int col, int coins)
{
    int val=0;

    if(isSafe(row,col,coins))
    {
        if(a[row][col]==1)
            coins+=1;

        else if(a[row][col]==2)
            coins-=1;

        if(coins<0)
            return;

        if(row==0)
        {
            if(coins>=max_coin)
            {
                max_coin=coins;
                return;
            }
        }

        max_coins1(row-1 , col-1, coins);
        max_coins1(row-1 , col+1, coins);
        max_coins1(row-1 , col, coins);
    }

    return;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        max_coin=-1;
        ans=-1;
    int n,i,j,max_coins;

    cin>>n;

    for(int i=0;i<n;++i)
        for(int j=0;j<5;++j)
        cin>>a[i][j];

    for(int i=0;i<5;++i)
        a[n][i]=0;

    for(int i=n-1;i>=0;--i)
    {
        //cout<<"Detonate Row:"<<i+1<<endl;
        detonate(i);
        max_coins1(n,2,0);
        //cout<<"max_coins:"<<max_coin<<endl;
        if(max_coin>ans)
            ans=max_coin;
        max_coin=-1;
        undetonate(i);
    }



    if(ans<0)
        ans=-1;

    cout<<ans<<endl;
    }

    return 0;
}
