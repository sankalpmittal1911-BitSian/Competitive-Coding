/*Jumping Game

You might remember the old computer arcade games. Here is one about Manao. 
The game level is an NxM grid of equal cells. The bottom of some cells has a platform at which Manao can stand. All the cells in the bottommost row contain a platform, thus covering the whole ground of the level. The rows of the grid are numbered from 1 to N starting from the top and the columns are numbered from 1 to M starting from the left. Exactly one cell contains a coin and Manao needs to obtain it. 
 Initially, Manao is standing on the ground, i.e., in the bottommost row. He can move between two horizontally adjacent cells if both contain a platform. Also, Manao has a ladder which he can use to climb. He can use the ladder to climb both up and down. If the ladder is L units long, Manao can climb between two cells (i1, j) and (i2, j) if both contain a platform and |i1-i2| <= L. Note that Manao carries the ladder along, so he can use it multiple times. You need to determine the minimum ladder length L which is sufficient to acquire the coin. 
Take a look at the following picture. On this level, Manao will manage to get the coin with a ladder of length 2. 
 
  You are given a int[] level containing N elements. The j-th character in the i-th row of level is 'X' if cell (i+1, j+1) contains a platform and '.' otherwise. You are also given ints coinRow and coinColumn. The coin which Manao seeks is located in cell (coinRow, coinColumn) and it is guaranteed that this cell contains a platform. 
Return the minimum L such that ladder of length L is enough to get the coin. If Manao can perform the task without using the ladder, return 0. 
Notes 

- Manao is not allowed to fall. The only way in which he may change his vertical coordinate is by using the ladder. 
  Constraints 

- level will contain N elements, where N is between 1 and 50, inclusive. 
- Each element of level will be M characters long, where M is between 1 and 50, inclusive. 
- Each element of level will consist of '.' and 'X' characters only. 
- The last element of level will be entirely filled with 'X'. 
- coinRow will be between 1 and N, inclusive. 
- coinColumn will be between 1 and M, inclusive. 
- level[coinRow - 1][coinColumn - 1] will be 'X'. 
  
Examples 

0)  
     

{"XXXX....",
 "...X.XXX",
 "XXX..X..",
 "......X.",
 "XXXXXXXX"}
 
2
 
4
 
 
Returns: 2
 The example from the problem statement. 
 
1)  
     {"XXXX",
 "...X",
 "XXXX"}
 
1
 1
 
Returns: 1
 Manao can use the ladder to climb from the ground to cell (2, 4), then to cell (1, 4) and then he can walk right to the coin. 
 
2)  
     

{"..X..",
 ".X.X.",
 "X...X",
 ".X.X.",
 "..X..",
 "XXXXX"}
 
1
 
3
 
Returns: 4
 With a ladder of length 4, Manao can first climb to cell (5, 3) and then right to (1, 3). 
 
3)  
     {"X"}
 
1
 
1
 
Returns: 0
 Manao begins in the same cell as the coin. 
 
4)  
     {"XXXXXXXXXX",
 "...X......",
 "XXX.......",
 "X.....XXXX",
 "..XXXXX..X",
 ".........X",
 ".........X",
 "XXXXXXXXXX"}
 
1
 
1
 
Returns: 2
 Pseudo code :

int dfs (int jump)
{
// if you reach destination, return 1

      // in stead of calling dfs for all neighbor cells, 
      // Run dfs with one condition

      /* Only if you can reach the next cell which is up or down 
     with given jump value, call dfs with that cell.
         take return value of dfs
         ret |= dfs(jump);    
      */
    return ret;   // if any of above dfs returns 1, return 1 from this function.
}

main()
{
      // Scan inputs
     // Start a loop with jump value 1 to 5
     for(jump = 1; jump <=50 ; jump++)
     {
               if(dfs(jump) == 1)
                  break;
     }
     Answer = jump;
}

Input:
6
10 12
0 0 0 0 1 1 1 1 0 1 1 0
1 1 0 0 1 0 1 1 0 0 1 1
1 1 1 3 1 0 1 0 0 0 1 1
0 0 0 0 0 0 1 1 1 1 0 0
0 0 0 0 0 0 0 0 1 1 0 0
0 0 0 1 1 0 0 0 1 0 0 0
0 0 0 0 0 0 0 0 0 0 0 1
1 1 1 1 1 1 0 0 1 1 0 0
0 0 1 1 0 1 1 0 1 0 1 1
2 1 1 1 1 1 1 1 1 1 1 1
8 10
3 1 1 1 1 1 1 1 1 1 
0 0 0 1 0 0 0 0 0 0 
1 1 1 0 0 0 0 0 0 0 
1 0 0 0 0 0 1 1 1 1 
0 0 1 1 1 1 1 0 0 1 
0 0 0 0 0 0 0 0 0 1 
0 0 0 0 0 0 0 0 0 1 
2 1 1 1 1 1 1 1 1 1 
6 5
0 0 3 0 0 
0 1 0 1 0 
1 0 0 0 1 
0 1 0 1 0 
0 0 1 0 0 
2 1 1 1 1
5 8
1 1 1 1 0 0 0 0
0 0 0 3 0 1 1 1
1 1 1 0 0 1 0 0
0 0 0 0 0 0 1 0
2 1 1 1 1 1 1 1
5 5
1 0 1 3 1
1 0 1 1 1
0 1 0 0 1
0 0 1 0 0
2 1 1 1 1
3 4
3 1 1 1 
0 0 0 1 
2 1 1 1 


*/

#include<iostream>
#include<fstream>
using namespace std;

bool res=false;

bool isSafe(int x,int y, int row , int col,bool **visit, char **mat)
{
    if(x<0 || y<0 || x>=row || y>=col || mat[x][y]=='.' || visit[x][y]==true)
        return false;
    return true;
}

bool isPossible(int jump, int x, int y, int row, int col, bool **visit, char **mat,int coin_row,int coin_col)
{
    if(isSafe(x,y,row,col,visit,mat))
    {
        visit[x][y]=true;

        if(x==coin_row && y==coin_col)
            return true;

        if(isPossible(jump,x,y-1,row,col,visit,mat,coin_row,coin_col))
        {
            return true;
        //visit[x][y-1]=false;
        }
        if(isPossible(jump,x,y+1,row,col,visit,mat,coin_row,coin_col))
        {
        return true;
//visit[x][y+1]=false;
        }
        for(int i=1;i<=jump;++i)
        {
            if(isPossible(jump,x+i,y,row,col,visit,mat,coin_row,coin_col))
            {
            return true;
            //visit[x+1][y]=false;
            }
            if(isPossible(jump,x-i,y,row,col,visit,mat,coin_row,coin_col))
            {
            return true;
            //visit[x-1][y]=false;
            }
        }

        return false;

    }

    return false;

}

int main()
{

    fstream myfile;

    myfile.open("Input.txt");

    int jump;
    int m,n;
    int ans=0;
    myfile>>m>>n;

    char **mat = new char*[m];
    for(int i=0;i<m;++i)
        mat[i]=new char[n];

    bool **visit=new bool*[m];

    for(int i=0;i<m;++i)
        visit[i]=new bool[n];

    for(int i=0;i<m;++i)
    {

        for(int j=0;j<n;++j)
        {
            myfile>>mat[i][j];
            visit[i][j]=false;
        }
    }

    int coin_row,coin_col;

    myfile>>coin_row>>coin_col;

    for(jump=0;jump<=50;++jump)
    {
        for(int i=0;i<m;++i)
    {

        for(int j=0;j<n;++j)
        {
            visit[i][j]=false;
        }
    }

        if(isPossible(jump,m-1,n-1,m,n,visit,mat,coin_row,coin_col))
        {
            ans=jump;
            break;
        }
    }

    cout<<ans<<endl;
    myfile.close();
    return 0;

}


