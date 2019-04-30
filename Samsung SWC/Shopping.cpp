/*Shopping
Problem code: SHOP

Crowd in the supermarketThe old tube screen to your computer turned out to be the cause of your chronic headaches. You therefore decide to buy one of these new flat TFT monitors. At the entrance of the computer shop you see that it is quite full with customers.

In fact, the shop is rather packed with customers and moving inside involves a certain amount of elbowing. Since you want to return home quickly to complete your half finished SPOJ tasks, you want to sidestep the crowd as much as possible. You examine the situation somewhat closer and realise that the crowding is less in some parts of the shop. Thus, there is reason for hope that you can reach your goal in due time, provided that you take the shortest way. But which way is the shortest way?

You sketch the situation on a piece of paper but even so, it is still a tricky affair. You take out your notebook from your pocket and start to write a program which will find the shortest way for you.
Input

The first line of the input specifies the width w and height h of the shop. Neither dimension exceeds 25.

The following h lines contain w characters each. A letter X symbolises a shelf, the letter S marks your starting position, and the letter D marks the destination (i.e. the square in front of the monitors). All free squares are marked with a digit from 1 to 9, meaning the number of seconds needed to pass this square.

There are many test cases separated by an empty line. Input terminates with width and height equal 0 0.
Output

Your program is to output the minimum number of seconds needed to reach to destination square. Each test case in a separate line. Movements can only be vertical and horizontal. Of course, all movements must take place inside the grid. There will always be a way to reach the destination.
Example

Sample input:
4 3
X1S3
42X4
X1D2

5 5
S5213
2X2X5
51248
4X4X2
1445D


Sample output:
4
23
*/

//Can use backtracking. Below is hybrid of BFS and djikstra

#include<iostream>

#include <fstream>

using namespace std;

int m,n;

int f=-1,r=-1;

char mat[25][25];


int dist[25][25];

struct
{
    int x;
    int y;
}q[10000];


void init1()
{
    f=-1;
    r=-1;
    for(int i=0;i<10000;++i)
    {
        q[i].x=0;
        q[i].y=0;
    }
}


bool isSafe(int x, int y)
{
    if(x<0 || y<0 || x>=m || y>=n || mat[x][y] == 'X')
        return false;

    return true;
}

int shortest(int s_x, int s_y, int d_x, int d_y)
{
    int dis[m][n];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            dis[i][j] = INT_MAX;


    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    q[++r].x = s_x;
    q[r].y = s_y;


    dis[s_x][s_y] = 0;


    while (f<r)
    {

        int xc = q[++f].x;
        int yc = q[f].y;
        int val;

        if(mat[xc][yc]=='S')
            val=0;
        else
            val = mat[xc][yc]-'0';


        for (int i = 0; i < 4; i++)
        {
            int x1 = xc + dx[i];
            int y1 = yc + dy[i];


            if (!isSafe(x1, y1))
                continue;


            if (dis[x1][y1] > dis[xc][yc] + val)
            {

                dis[x1][y1] = dis[xc][yc] + val;

                if(mat[x1][y1]!='D')
                {
                q[++r].x = x1;
                q[r].y = y1;
                }
            }
        }
    }


    return dis[d_x][d_y];
}


int main()
{
    fstream myfile;

    myfile.open("Input.txt");

    myfile>>m>>n;

    init1();

    int sx,sy,dx,dy;

    for(int i=0;i<m;++i)
    {
        for(int j=0;j<n;++j)
        {
            myfile>>mat[i][j];

            if(mat[i][j]=='S')
            {
                sx=i;
                sy=j;
            }

            if(mat[i][j]=='D')
            {
                dx=i;
                dy=j;
            }

        }
    }




    cout<<shortest(sx,sy,dx,dy)<<endl;

    return 0;



}
