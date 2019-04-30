/*Palindrome IP Address
An IP address is a 32-bit integer, represented as a group of four decimal 8-bit integers (without leading zeroes), and separated by dots. For example, record 0.255.1.123 shows a correct IP address and records 0.256.1.123 and 0.255.1.01 do not. In the given problem an arbitrary group of four 8-bit integers is a correct IP address.
Our hero Polycarp’s still works as a system administrator in some large corporation. He likes beautiful IP addresses. To check if some IP address is beautiful, he should do the following:
1.  Write out in a line four 8-bit numbers of the IP address, without the dots;
2.  Check if the resulting string is a palindrome.
Let us remind you that a palindrome is a string that reads the same from right to left and from left to right.
For example, IP addresses 12.102.20.121 and 0.3.14.130 are beautiful (as strings "1210220121" and "0314130" are palindromes), and IP addresses 1.20.20.1 and 100.4.4.1 are not.
Polycarpus wants to find all beautiful IP addresses that have the given set of digits. Each digit from the set must occur in the IP address at least once and maximum twice. IP address must not contain any other digits. Help him to cope with this difficult task.
Set of digits will contain minimum 2 digits and maximum 6 digits.
Input: 
5 
2 
2 5 
3 
0 1 9 
4 
0 1 2 3 
5 
0 1 2 3 4 
6 
1 2 3 4 5 6 

Output: 
#1 2 
#2 38 
#3 236 
#4 268 
#5 24
*/





#include<iostream>
#include<fstream>

using namespace std;

int count1;
bool palindrom(int ans[100],int j){
  for(int i=0;i<j/2;i++){
    if(ans[i]!=ans[j-i-1])return false;
  }
  return true;
}
void permute(int ans[100],int value,int point,int* count, int * array,int n,int j){

  if(point==4){
    for(int i=0;i<n;i++){
      if(count[i]==0){return;}
    }
    if(palindrom(ans,j))count1++;
    return;
  }

  for(int i=0;i<n;i++){
    if(count[i]!=2)
    {
      int value1=value*10+array[i];
      count[i]++;
      ans[j]=array[i];
      if(value1<256){
        permute(ans,0,point+1,count,array,n,j+1);
        }
      if(value1!=0 && value1<256)permute(ans,value1,point,count,array,n,j+1);
      count[i]--;
    }

  }
}
int main(){
  int test;

  fstream myfile;

  myfile.open("Input.txt");

  myfile>>test;
  while(test--){
    count1=0;
    int ans[100];
    for(int i=0;i<100;i++){ans[i]=0;}
    int n;
    myfile>>n;
    int arr[n];
    int count[n];
    for(int i=0;i<n;i++){myfile>>arr[i];count[i]=0;}
    permute(ans,0,0,count,arr,n,0);
    cout<<count1<<endl;
  }

  myfile.close();
  return 0;
}
