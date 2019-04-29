/*Samsung wants to explore some of the rare elements for its semiconductor manufacturing. Scientists use one vehicle to explore the region in order to find the rare elements. The vehicle can move only in explored region where roads have already been constructed. The vehicle cannot move on unexplored region where roads are not there.  In the current situation, rare elements are present in explored region only. Unexplored regions do not contain any rare elements.
Square region is provided for exploration. Roads are represented by 1 and where roads are not present that area is represented by 0. Rare elements will only be on the roads where regions have already been explored. Vehicle can move in four directions – up, down, left and right.
The shortest path for vehicle to a rare element position is called Moving Path. The longest of the paths to all rare elements from a region called Longest Distance. 
Scientists need to construct one research center so that the research center will be at the position where the longest path to the rare elements will be shortest. This is called Shortest Longest Distance.
 
In the above picture, Red, Blue and Green area represents Rare Element area. (2, 2) is represented as Red, (2, 8) is represented as Blue and (7, 8) is represented as Green. So there are three rare elements. 
If research center is constructed at (4, 4) then distance to Red rare element will be 4, distance to Blue rare element will be 6 and distance to Green rare element will be 7. So the Longest distance will be 7.
 

Now using the same region above, if research center is constructed at (4, 5) then distance to Red rare element will be 5, distance to Blue rare element will be 5 and distance to Green rare element will be 6. So the Longest distance will be 6.
So when research center is constructed at (4, 5) then the longest distance will be shortest. And the value of the Shortest Longest Distance will be 6. This will be the output.
There can be multiple locations from where the shortest longest distance can be same. For example if research center is constructed at (5, 5) then still the Shortest Longest distance will be 6.
So write a program to find the Shortest Longest Distance.

Constraints:
• The region provided will be square region i.e. NxN (where 5 <=  N <= 20).
• There can be minimum of 2 rare elements and maximum of 4 rare elements, i.e. 2 <= C <= 4.
• Roads are represented by 1 while no road area is represented by 0.
• Vehicle can move only on roads in explored area.
• The rare elements will only be present where road are there. Rare elements will not be present where roads are not present.
• Vehicle can move in UP, DOWN, LEFT and RIGHT directions.
• The starting index for rare element is considers as 1.
•  
Input:
• First line will be the number of test cases. Second line will indicate region area (N) and number of rare elements (C). Next C lines will contain the position of rare elements. After that N lines will provide the region details where to tell where roads are present and where roads are not present.
 
Output:
• Output #testcase followed by space and then shortest longest distance.

Sample Input:
5
5 2
4 3
3 4
1 1 0 0 0
1 1 0 0 0
1 1 1 1 1
1 1 1 0 1
1 1 1 1 1
8 2
5 6
6 4
1 1 1 1 1 1 0 0
1 1 1 1 1 1 1 0
1 1 0 1 0 1 1 0
1 1 1 1 0 1 1 0
1 1 1 1 1 1 1 0
1 1 1 1 1 1 1 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
10 3
8 2
5 3
7 1
0 0 0 1 1 1 1 1 1 0
1 1 1 1 1 1 1 1 1 0
1 0 0 1 0 0 0 0 1 0
1 1 1 1 1 1 1 1 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 0 0 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1
15 4
11 15
15 9
1 2
14 3
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 1 1 1 1 1 1 1 1 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 0 1 0 0 0 1 1 1 1 1 1 1 0 1
0 0 1 1 1 1 1 1 1 1 1 1 1 1 1
20 4
13 6
20 4
1 2
17 16
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0

Sample Output:
#1 1
#2 2
#3 2
#4 12
#5 15
*/

//DFS will time out (why?). Use BFS.

#include<iostream>
#include<bits/stdc++.h>
#include<fstream>

using namespace std;
int counter = 0;
int a[22][22];
int x[4];
int y[4];
bool visit[22][22];
int N;
int ele; //Number of rare elements
int f,r;

struct
{
 int x;
 int y;
 int d;
}q[1000000];

void unvisit()
{
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            visit[i][j]=false;
        }
    }
}

void initialize_queue()
{
    r=-1,f=-1;

    for(int i=0;i<1000000;++i)
    {
        q[i].x=0;
        q[i].y=0;
        q[i].d=0;
    }
}

bool isSafe(int x, int y)
{
    /*
    if(x>=N || y>=N || x<0 || y<0 || a[x][y]!=1 || visit[x][y]==true )
        return false;
    return true;
    */
    return x>=0 && y>=0 && x<N && y<N && a[x][y]==1 && !visit[x][y];
}
int max_distance(int xC, int yC, int m_dis)
{
   ++r;
   q[r].x=xC;
   q[r].y=yC;
   q[r].d=0;

   while(f<r)
   {
       int flag=0;

       ++f;

       //cout<<"Deleted:"<<endl;

       int xc = q[f].x;
       int yc = q[f].y;
       int dis = q[f].d;
       visit[xc][yc]=true;

       //cout<<xc<<" "<<yc<<" "<<f<<" "<<r<<endl;




       for(int i=0;i<ele;++i)
       {
           if(visit[x[i]][y[i]]==true)
            ++flag;

           if(xc==x[i] && yc==y[i])
            m_dis=max(m_dis,dis);

       }

        //cout<<flag<<" "<<ele<<endl;
       if(flag==ele)
        break;


       if(isSafe(xc-1,yc))
       {
           ++r;
           q[r].x=xc-1;
           q[r].y=yc;
           q[r].d=dis+1;
           //visit[xc-1][yc]=true;
           //cout<<"Inserted:"<<endl;
           //cout<<xc-1<<" "<<yc<<endl;
       }

       if(isSafe(xc+1,yc))
       {
           ++r;
           q[r].x=xc+1;
           q[r].y=yc;
           q[r].d=dis+1;
           //visit[xc+1][yc]=true;
           // cout<<"Inserted:"<<endl;
           //cout<<xc+1<<" "<<yc<<endl;
       }

       if(isSafe(xc,yc-1))
       {
           ++r;
           q[r].x=xc;
           q[r].y=yc-1;
           q[r].d=dis+1;
           //visit[xc][yc-1]=true;
            //cout<<"Inserted:"<<endl;
           //cout<<xc<<" "<<yc-1<<endl;
       }

       if(isSafe(xc,yc+1))
       {
           ++r;
           q[r].x=xc;
           q[r].y=yc+1;
           q[r].d=dis+1;
           //visit[xc][yc+1]=true;
            //cout<<"Inserted:"<<endl;
           //cout<<xc<<" "<<yc+1<<endl;

       }
   }

   return m_dis;


}

int main()
{

    fstream myfile;

    myfile.open("Input.txt");



    myfile>>N>>ele;


    int min_dis=999;

    for(int i=0;i<ele;++i)
    {
        myfile>>x[i]>>y[i];

       // cout<<x[i]<<y[i]<<endl;
    }

    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            myfile>>a[i][j];
        }
    }

    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            if(a[i][j]==1)
            {
                //cout<<"BREAK"<<endl;
                unvisit();
                initialize_queue();
                //cout<<i<<" "<<j<<endl;
                min_dis=min(min_dis,max_distance(i,j,-999));
            }


                }

            }




    cout<<min_dis<<endl;

    myfile.close();

    return 0;




}
