/*Brief Description of the problem:
Samsung wants to introduce the promotions in mobile sale.  They want to setup a booth to sell mobile phones.  They will club all areas of same mobile model with 1 single booth.   In areas (marked zero), where Samsung mobile is not established, they will consider selling the mobiles that are famous in adjacent areas of higher configuration.  
We are given N*N matrix which can have a number between 0 and 5.

Sample input:

5 5 1 4 4
4 0 2 4 2
5 0 0 2 0
5 4 3 0 1
1 3 3 2 1

Sample Output:

5 5 1 4 4
4 5 2 4 2
5 5 5 2 2
5 4 3 3 1
1 3 3 2 1

In this case, 11 independent clusters are formed. This means 11 booths have to be setup.

We need to consider selling the mobile that are famous in adjacent areas. In below case, count is like this:
S3 mobile – 3
S2 mobile – 2
S1 mobile – 2

As S3 is famous in neighboring area, so S3 will be considered for selling at this location.

    2 0
4 3 0 1
3 3 2 1



Problem Analysis:
We need to find clusters of Samsung mobiles around the place where Samsung mobile is not established yet ( marked 0 in matrix). After finding clusters, we can choose the famous handset of higher configuration. 

Let’s take below example, 

5 5   
4 0 2 
5 0 0 2
5 4 3  
  3 3 

While calculating for 0 located at (1,1) position in matrix, we need to find clusters around all the 0s which are connected with each other. For this group of 0, we can find clusters of Samsung mobiles around it and replace these 0s with famous mobile having highest configuration.

We can calculate cluster using BFS or DFS.  For above case, we will find below clusters around these 0s:

S5 Mobile – 4 (Marked in Orange )
S4 Mobile -  2 (marked in red)
S3 Mobile – 3
S2 Mobile – 2
S1 Mobile - 0

Highest configuration famous mobile is S5; hence we can replace these 0s with S5 mobile.

5 5   
4 5 2 
5 5 5 2
5 4 3  
  3 3 











Approaches to the problem of traversal:

1)  Recursive Depth-first Search:
Find clusters around “Zero” or “Group of Zeros” which are connected using recursive DFS approach. Its simple approach using recursive Calls. However, it would be little slow as compare to other two approaches. DFS solution is given by Sasi. (Source: from sasi folder)

 



2)  DSF using Stack (Non Recursive):
We can avoid recursive function calls by implementing our own stack. 

STACK s
visited[ ]
DFS(v)
         push( s, v )
         WHILE NOT isEmpty( s ) 
                  v ← pop(s)
                  IF NOT visited[v]
                           visit( v )
                           FOR each w in adjacency( v )  //adjacent in UP, RIGHT, DOWN, LEFT  dir
                                                  IF NOT visited[w] and Value is same as previous Node
                                                              push(s, w)
















3)  Breadth-First Search:
We can find clusters around Zeros using BFS approach as well. BFS would need queue implementation.  

BFS(G,v) // Graph G, Starting point of search v
  Generate queue
  Insert the starting point v to the queue
  Indicate the point v as visited
  WHILE queue is not empty
    t ← return the first element of queue
    FOR every line connected to t
      u ← neighboring point of t  
      If u is not visited point, and value is same as pervious Node
      insert u into queue, and indicate as visited


 


Sample Input:

3
5
5 5 1 4 4 
4 0 2 4 2
5 0 0 2 0 
5 4 3 0 1
1 3 3 2 1
10
1 3 5 1 4 0 0 4 2 1
1 1 2 1 1 0 5 0 2 1
5 0 2 0 4 4 4 0 1 1
0 2 2 4 0 5 4 2 1 3
1 1 2 2 2 3 3 2 1 1
5 1 1 2 0 3 3 2 2 1
3 1 1 1 0 0 1 2 2 5
3 1 4 1 2 0 4 0 0 5
4 0 3 3 1 3 3 0 0 1
5 0 3 1 4 3 3 1 2 3
20
0 2 1 0 1 3 3 3 3 4 4 1 1 1 4 1 1 4 1 4
0 2 3 5 1 2 3 3 3 3 4 2 1 3 2 2 1 1 1 3
0 2 1 5 1 2 2 2 0 3 2 3 4 2 1 3 3 0 1 1
1 5 4 5 1 2 5 5 5 5 2 5 5 2 0 0 3 3 5 4
1 0 5 5 3 5 3 0 4 5 5 5 1 0 1 1 3 4 0 0
4 5 3 4 4 5 3 3 0 0 3 3 1 3 1 3 2 5 0 0
3 2 0 0 0 3 4 1 1 1 1 3 5 2 1 3 1 4 0 5
2 2 0 2 3 3 3 0 1 5 1 3 5 2 5 3 4 4 0 5
3 4 0 1 1 1 0 4 4 4 4 1 5 0 4 5 3 4 4 4
3 2 0 1 4 4 3 0 0 0 3 5 1 0 1 4 1 3 4 4
0 3 1 1 1 1 1 1 2 2 3 3 1 0 5 4 4 4 4 4
4 2 5 3 4 4 4 1 2 5 5 5 4 1 1 1 4 1 0 5
4 2 5 1 4 2 5 2 0 1 5 2 4 1 4 1 1 0 0 0
1 2 3 0 1 4 2 2 4 1 1 0 4 4 4 5 4 1 0 0
3 2 0 1 1 1 2 1 3 1 0 4 1 4 4 2 4 3 3 0
3 3 5 4 1 1 1 1 3 2 4 4 4 4 4 3 3 3 3 4
4 3 1 1 1 1 1 1 1 3 2 2 0 5 4 4 4 5 0 0
3 3 2 0 5 0 3 3 1 3 2 4 0 4 0 4 4 2 4 4
1 4 4 3 4 5 2 4 4 4 4 4 0 5 0 4 0 3 1 0
5 4 4 5 2 3 3 0 0 5 2 4 3 3 2 3 4 4 5 0

Sample Output:

#1: 11
#2: 31
#3: 130
*/

//You can optimize using BFS (will it?)

#include<iostream>
#include<fstream>

using namespace std;

int mat[100][100];

bool visit[100][100];

int N;

int c[6];

void init()
{
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            visit[i][j]=false;
        }
    }
}

void init2()
{
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            if(mat[i][j]!=0)
            visit[i][j]=false;
        }
    }
}

bool isSafe(int i,int j)
{
    if(i<0 || i>=N || j<0 || j>=N || visit[i][j]==true)
        return false;

    return true;
}

void zero_count()
{
    for(int i=0;i<6;++i)
        c[i]=0;
}

void dfs_count(int i, int j, int val)
{
    if(isSafe(i,j) && mat[i][j]!=0 && mat[i][j]==val)
    {
        visit[i][j]=true;

        ++c[val];

        //cout<<val<<" "<<c[val]<<endl;

        dfs_count(i-1,j, val);
        dfs_count(i+1,j, val);
        dfs_count(i,j-1, val);
        dfs_count(i,j+1, val);


    }

    return;
}


void dfs_zero(int i, int j)
{
    if(isSafe(i,j) && mat[i][j]==0)
    {

    visit[i][j]=true;

        if(isSafe(i-1,j))
        dfs_count(i-1,j, mat[i-1][j]);
        if(isSafe(i+1,j))
        dfs_count(i+1,j, mat[i+1][j]);
        if(isSafe(i,j-1))
        dfs_count(i,j-1, mat[i][j-1]);
        if(isSafe(i,j+1))
        dfs_count(i,j+1, mat[i][j+1]);

        dfs_zero(i-1,j);
        dfs_zero(i+1,j);
        dfs_zero(i,j-1);
        dfs_zero(i,j+1);

    }

    return;
}

void replace_zero(int i,int j, int val)
{
    if(isSafe(i,j) && mat[i][j]==0)
    {
        visit[i][j]=true;

        mat[i][j]=val;

        replace_zero(i-1,j,val);
        replace_zero(i+1,j,val);
        replace_zero(i,j-1,val);
        replace_zero(i,j+1,val);
    }

    return;
}

void count_clusters(int i, int j, int val)
{
    if(isSafe(i,j) && mat[i][j]==val)
    {
        visit[i][j]=true;
        count_clusters(i-1,j, val);
        count_clusters(i+1,j, val);
        count_clusters(i,j-1, val);
        count_clusters(i,j+1, val);
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

    myfile>>N;

    int clus=0;

    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            myfile>>mat[i][j];
        }
    }

    init();

    zero_count();

    int max_val=-1;

    int rep[N*N];

    for(int i=0;i<N*N;++i)
        rep[i]=0;

    int c1=-1;

    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            if(mat[i][j]==0 && visit[i][j]==false)
            {
                //cout<<"Cluster:"<<endl;
                dfs_zero(i,j);
                ++c1;
                for(int k =1;k<6;++k)
                {
                    if(c[k]>=max_val)
                    {
                        max_val=c[k];
                        rep[c1]=k;
                    }

                }

                //cout<<"Replace:"<<rep[c1]<<endl;
                max_val=-1;

                zero_count();
                init2();

            }
        }
    }

    init();
    c1=-1;

    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            if(mat[i][j]==0 && visit[i][j]==false)
            {
                //cout<<rep[++c1]<<endl;
                replace_zero(i,j,rep[++c1]);
            }
        }
    }

    init();

    /*for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }*/

    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            if(visit[i][j]==false)
            {
                 ++clus;
                count_clusters(i,j,mat[i][j]);

            }
        }
    }

    cout<<clus<<endl;

    }


    myfile.close();

    return 0;
}
