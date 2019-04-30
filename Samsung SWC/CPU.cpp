/*You have certain number of CPU, memory and computer boards. You can build computer models from these raw materials. You can have up to 8 different models to choose from. Each model requires some no. of CPU, no. of memory, no. of boards and it will fetch X Rs. You can sell them as models or individually send CPU, memory with unit price. However, you can not sell individual boards.
Given no. of CPU, memory, boards and their individual prices and upto 8 model configuration and price, find maximum profit that you can earn.
Ex. 
 CPU 		Memory 	Board
No. of units       5 		10 		10

 	   CPU  Memory
unit price 1         1

Models CPU Memory Board Profit
1 	2 	1 	1 	8
2 	1 	1 	1 	6

Here, we have total 5 CPU, 10 memory and 10 boards with us. With that, we can build 5 computers of model-2 and then remaining 5 unit memory can be sold individually. Total 6*5 + 5 = 35
Or we can build 2 model-1 (2*8) + 1 model-2 (6) + 5 memory (1*5) = 27
Or we can sell all material individually (5 * 1) + (10*1) = 15
Input:
Total test cases. For each test case, no. of CPU, memory, board and unit price of CPU and memory.
Next line will have N – total number of computer models. Next N lines will have no. of CPU, memory, board required in this model and profit by selling this model.
Output:
Maximum profit value
*/

//You can use backtracking or bruteforce:

//Here is a DP solution

#include<iostream>
#include<fstream>
#include<bits/stdc++.h>


#include<iostream>
#include<fstream>
#include<bits/stdc++.h>


using namespace std;

int main()
{
    fstream myfile;

    myfile.open("Input.txt");

    int num_models;

    myfile>>num_models;

    num_models+=2;

    int n_cpu,n_mem,n_b;
    int pr_cpu,pr_mem;

   myfile>>n_cpu;
   myfile>>n_mem;
   myfile>>n_b;
   myfile>>pr_cpu;
   myfile>>pr_mem;


    int cpu[num_models],mem[num_models],b[num_models],p[num_models];

    cpu[0]=1;
    mem[0]=0;
    b[0]=0;
    p[0]=pr_cpu;

    cpu[1]=0;
    mem[1]=1;
    b[1]=0;
    p[1]=pr_mem;

//cout<<num_models;

    for(int i=2;i<num_models;++i)
    {
        myfile>>cpu[i]>>mem[i]>>b[i]>>p[i];
    }

    int dp[n_cpu+1][n_mem+1][n_b+1];

    memset(dp,0,sizeof dp);
        for(int j=0;j<=n_cpu;++j)
        {
            for(int k=0;k<=n_mem;++k)
            {
                for(int l=0;l<=n_b;++l)
                {
                    for(int i=0;i<num_models;++i)
                    {
                    if(cpu[i]<=j && mem[i]<=k && b[i]<=l)
                    {
                        dp[j][k][l]=max(p[i] + dp[j-cpu[i]][k-mem[i]][l-b[i]] , dp[j][k][l] );


                    }

                    }
                }
            }
        }



    int ans=-1;

    for(int i=0;i<=n_b;++i)
        ans=max(ans,dp[n_cpu][n_mem][i]);

    cout<<ans<<endl;
     myfile.close();
    return 0;


}

