/*You are given a simple map of an archipelago. Can you determine how many islands it shows?

The map consists of grid squares with characters, where '#' indicates land and '.' indicates water. Two land squares belong to the same island if they are neighbouring grid squares, which means their x coordinates and y coordinates differ by at most 1.
Input

The first line of the input contains a number T = 20 which indicates the number of test cases to follow.

Each test case starts with a line containing two numbers n and m (1 = n,m = 200), the number of rows and the number of columns of the grid, respectively. The following n lines contain m characters each and describe the map to be processed. You may assume that the map contains only characters '#' and '.', and that the border of the map consists only of water (character '.').
Output

For each test case print in a line the number of islands shown on the corresponding map in the input.
Example

Input:
2
1 1
.
6 4
....
..#.
.#..
....
.##.
....

Output:
0
2*/


#include<iostream>
#include<fstream>

using namespace std;

int m,n;

char mat[100][100];

bool visit[100][100];

void init()
{
    for(int i=0;i<m;++i)
        for(int j=0;j<n;++j)
        visit[i][j]=false;
}

bool isSafe(int x, int y)
{
    if(x<0 || x>=m || y<0 || y>=n || visit[x][y]==true || mat[x][y]=='.')
        return false;

    return true;
}

void dfs(int x, int y)
{
    if(isSafe(x,y))
    {
        visit[x][y]=true;

        dfs(x-1,y);
        dfs(x+1,y);
        dfs(x,y-1);
        dfs(x,y+1);
        dfs(x-1,y-1);
        dfs(x+1,y+1);
        dfs(x+1,y-1);
        dfs(x-1,y+1);

    }

    return;
}


int main()
{
    fstream myfile;

    myfile.open("Input.txt");

    int t;

    myfile>>t;

    while(t--)
    {

        myfile>>m>>n;

        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                myfile>>mat[i][j];
            }
        }

        init();

        int isl=0;

        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(mat[i][j]=='#' && visit[i][j]==false)
                {
                    ++isl;
                    dfs(i,j);
                }
            }
        }

        cout<<isl<<endl;
    }

    myfile.close();
    return 0;
}
