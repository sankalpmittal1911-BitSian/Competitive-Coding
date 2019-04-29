/*On Sachin Tendulkar road in Mumbai, some cars are stuck with no fuel between Gasoline and Diesel station. These cars require either Gasoline or Diesel. One robot is available at Gasoline station which can refill cars with Fuel. Each car needs only one liter of fuel and robot can carry maximum 2 liters of fuel either Gasoline or Diesel at a time.
Cars are stuck in such a way that there is equal distance between each car. And also same distance between Gasoline Station to First Car and Diesel station to Last Car. Let’s assume that distance between each car is 1 KM. And so same is distance between Gasoline Station to first Car and Diesel station to Last Car.
We need to find minimum how many KMs Robot need to travel to refill fuel to all cars.
NOTE: Robot can also discard its remaining fuel to select new fuel.
There can be maximum 8 cars only.
Run Time Constrain: 3 Seconds for 50 Test Cases.
Input Format:
First line contains number of test cases.
Second line contains N i.e. Number of Cars for First Test Case.
Third line contains N values which can be 1 or 2. 1 means car requires Gasoline and 2 means car requires Diesel.
Fourth line onwards would be same as 2nd and 3rd line for remaining test cases.
Sample Input:
5
3
2 1 2
5
1 2 1 2 1
5
2 1 1 2 1
8
2 2 1 1 1 2 1 1
8
2 2 2 2 2 2 2 2
*/

#include<iostream>
#include<fstream>
#include<bits/stdc++.h>

using namespace std;

int n, *arr, mdist;

void fuel(int pos, int gd, int stOrmid, int nfill, int dist, int fuelLeft)
{
	if(mdist<dist) return;

	if(nfill==n)
	{
		if(dist<mdist)
			mdist=dist;
		return;
	}

	if(stOrmid==0)
	{
		fuel(-1, 1, 1, nfill, dist+pos+1,0);
		fuel(n, 2, 2, nfill, dist+n-pos,0);
		if(fuelLeft==0)
		{

			return;
		}


		int i;
		if(gd==1)
		{
			for(i=0;i<n;i++)
			{
				if(arr[i]==1)
				{
					arr[i]=0;
					fuel(i, 1, 0, nfill+1, dist+abs(i-pos),0);
					arr[i]=1;
				}
			}
		}
		else if(gd==2)
		{
			for(i=0;i<n;i++)
			{
				if(arr[i]==2)
				{
					arr[i]=0;
					fuel(i, 2, 0, nfill+1, dist+abs(i-pos),0);
					arr[i]=2;
				}
			}
		}

	}
	else if(stOrmid==1)
	{
		int i;
		for(i=0;i<n;i++)
		{
			if(arr[i]==1)
			{
				arr[i]=0;
				fuel(i, 1, 0, nfill+1, dist+i+1,1);
				arr[i]=1;
			}
		}
		fuel(n, 2, 2, nfill, dist+n+1,0);
	}
	else if(stOrmid==2)
	{
		int i;
		for(i=0;i<n;i++)
		{
			if(arr[i]==2)
			{
				arr[i]=0;
				fuel(i, 2, 0, nfill+1, dist+n-i,1);
				arr[i]=2;
			}
		}
		fuel(-1, 1, 1, nfill, dist+n+1,0);
	}

}

int main()
{
    fstream myfile;
    myfile.open("Input.txt");
	int t;
	myfile>>t;
	while(t--)
	{
		myfile>>n;
		arr=new int[n];
		int i;
		for(i=0;i<n;i++)
		{
			myfile>>arr[i];
		}
		mdist=100000;

		fuel(-1,1,1,0,0,0);
		printf("%d\n",mdist);
		free(arr);
	}

	myfile.close();

	return 0;
}

