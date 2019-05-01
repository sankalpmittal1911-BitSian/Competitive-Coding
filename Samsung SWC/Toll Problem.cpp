/*Toll Problem
You need to go past maximum 20 toll-booths in a forest. At each toll, you can do one of the following:
?	Either Pay the toll
?	Or Pay double toll and hire all the soldiers from that toll
?	Or Have battle with the soldiers of that toll and do not pay the toll.
Initially, you do not have any soldiers with you. You may hire few soldiers in subsequent tolls. You can have battle option only if you have at least same number or more soldiers with you than the number of soldiers at that toll post. 
When you take part in any battle, you lose same number of soldiers as number of soldiers at that toll post. Also, each soldier can take part in only 3 battles. After that, the soldier dies naturally.
Ex. You have 100 soldiers with you. Toll has 60 soldiers. If you decide to do battle, after it you have only 40 soldiers with you. Out of those 40, few might have taken part in 3 battles, few in 2 battles and few in 1 battles. Those who have already taken part in 3 battles also die.
Your aim is to minimize number of rupees requires to go past all tolls.
Input:
T test cases. For each case, N ? number of toll posts. For next N lines, it will have S ? no. of soldiers at that post and C ? toll to pay at that post. 
Output:
Minimum number of rupees requires to go past all tolls.
Input:
2
7
10 100
70 5
80 15
20 60
50 90
30 80 
10 10
9
600 800
300 400
300 400
1000 400
300 600
100 300
600 300
600 500
1000 300
Output:
#1 150
#2 3000*/


#include<iostream>

#include <fstream>

using namespace std;

int N;

int min_cost = 99999;

struct
{
    int toll;
    int soldiers;
}booth[20];

//Soldiers0 --> Fought 0 battles
//Soldiers1 --> Fought 1 battles
//Soldiers2 --> Fought 2 battles

void min_toll(int num, int cost, int soldiers0, int soldiers1, int soldiers2)
{
    int soldiers = soldiers0+soldiers1+soldiers2;

    if(cost>min_cost)
        return;

    if(num==N)
    {
        if(cost<min_cost)
        {
            min_cost=cost;
            return;
        }
    }


    //Battle

    if(soldiers>0 && soldiers>=booth[num].soldiers && booth[num].soldiers>0)
    {
        int backup = booth[num].soldiers;
        booth[num].soldiers = 0;

        if(backup>soldiers1+soldiers2)
        {

            soldiers0 = soldiers - backup;
            soldiers1=0;
            soldiers2=0;
        }
        else if(backup>soldiers2)
        {
            soldiers1 = soldiers1+soldiers2 - backup;
            soldiers2=0;
        }

        min_toll(num+1,cost,0,soldiers0,soldiers1);
        booth[num].soldiers = backup;

    }

    //Pay

    min_toll(num+1,cost+booth[num].toll,soldiers0,soldiers1,soldiers2);

    //Hire

    if(booth[num].soldiers>0)
    {
        int backup = booth[num].soldiers;
        booth[num].soldiers = 0;
        min_toll(num+1, cost+ 2*booth[num].toll ,soldiers0+backup,soldiers1, soldiers2);
        booth[num].soldiers = backup;
    }
}


int main()
{
    int t;


    fstream myfile;

    myfile.open("Input.txt");

    myfile>>t;

    while(t--)
    {

        min_cost = 99999;


    myfile>>N;

    for(int i = 0; i<N; ++i)
        myfile>>booth[i].soldiers>>booth[i].toll;

    min_toll(0,0,0,0,0);

    cout<<min_cost<<endl;
    }

    myfile.close();

    return 0;
}

