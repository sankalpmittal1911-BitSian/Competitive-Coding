/*This problem was recently asked by Google.

Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?*/

#include <bits/stdc++.h> 
  
using namespace std; 
  
int main() 
{ 
    int n;
    int k;
    cin >> n;
    cin>>k;
    int list[n];
    bool flag = false;
    for(int i=0;i<n;++i)
      cin>>list[i];
  
    unordered_set <int> S;
    int n = 16; 
    
    for(int i=0;i<n;++i)
    {
      int temp = k - list[i];
      
      if(S.find(temp)!=S.end())
      {
        flag = true;
        break;
      }
      
      S.insert(list[i]);
    } 
  
  if(flag == true)
    cout<<"True"<<endl;
  else
    cout<<"False"<<endl;
  
  return 0;
}


