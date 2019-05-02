/*Mr. Lee is planning to attend a Running competition.
He is trying to find the minimum time required to cover the entire distance with his energy levels.
There are 5 different profiles available to cover the distance. Entire distance can be covered by using any combination of these 5 profiles. Any selected profile should be used for entire 1 km. 
For each profile , there is a time associated with it, this represents the time required to cover 1 km of distance. 
For each profile , there is energy associated with it, this represents the required energy level to cover 1 km.  You can use same profile multiple times.
Profile 1 2 3 4 5
Time required to cover 1 km 5min 10sec  5min 20sec  5min 30sec  5min 40sec  5min 50sec
Energy Required to cover 1 km 7 5 4 2 1

You will be given with Total Energy(E) available, and total distance(D) to be covered. Find the minimum time required to cover the entire distance provided that your combination of profiles shouldn’t exceed total energy. 
Input: No. of test cases. Then each line will have total energy (E) and Total distance (D). Then next 5 lines will have 5 profiles with M,N,e where M is minutes, N is seconds and e is energy required to cover 1 km.
2
100 30
1 0 10
2 0 1
3 0 1
4 0 1
5 0 1
130 30
4 50 7
5 0 5
5 10 4
5 20 3
5 30 2

Output:
#1 53 0
#2 153 20*/

#include<iostream>
#include<fstream>
#include<bits/stdc++.h>

using namespace std;



int main()
{
    fstream myfile;

int time[5],energy[5];
int m_time=INT_MAX;
int t=0;
int t_d,t_e;

int pu[5];

    myfile.open("Input.txt");

    myfile>>t_e>>t_d;
    int d=0,e=0;

    for(int i=0;i<5;++i)
    {
        int x,y;

        myfile>>x>>y>>energy[i];

        pu[i]=min(t_d,t_e/energy[i]);

        //cout<<pu[i];

        time[i]=60*x + y;
    }


   for(int i=0;i<=pu[0];++i)
   {
       for(int j=0;j<=pu[1];++j)
       {
           for(int k=0;k<=pu[2];++k)
           {
               for(int l=0;l<=pu[3];++l)
               {
                   for(int m=0;m<=pu[4];++m)
                   {
                       d=i+j+k+l+m;
                       e=i*energy[0]+j*energy[1]+k*energy[2]+l*energy[3]+m*energy[4];
                       t = i*time[0]+j*time[1]+k*time[2]+l*time[3]+m*time[4];

                       //cout<<e<<" "<<d<<endl;
                       
                       if(t>m_time)
                           break;

                       if(d==t_d && e<=t_e)
                       {
                           m_time=min(m_time,t);
                       }

                   }
               }
           }
       }
   }



    cout<<m_time<<endl;

    myfile.close();

    return 0;
}

