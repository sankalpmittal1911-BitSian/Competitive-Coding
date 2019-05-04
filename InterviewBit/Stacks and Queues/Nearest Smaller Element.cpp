/*Given an array, find the nearest smaller element G[i] for every element A[i] in the array such that the element has an index smaller than i.

More formally,

G[i] for an element A[i] = an element A[j] such that 
    j is maximum possible AND 
    j < i AND
    A[j] < A[i]
Elements for which no smaller element exist, consider next smaller element as -1.

Example:

Input : A : [4, 5, 2, 10, 8]
Return : [-1, 4, -1, 2, 2]

Example 2:

Input : A : [3, 2, 1]
Return : [-1, -1, -1]*/

vector<int> Solution::prevSmaller(vector<int> &A) {
    
   
    
    stack <int> S;
    
    vector <int> res;
  
    
    int near_min=-1,i,j,flag=0;
    
    for(i=0;i<A.size();++i)
    {
        near_min = -1;
      
        
        
            
        
        while(!S.empty())
        {
            if(S.top()<A[i])
            {
                near_min=S.top();
                break;
            }
              
            S.pop();
        }
        
        
       
        
        res.push_back(near_min);
        S.push(A[i]);
        
      
        
                
            
        
            
            
        }
        
    
    return res;
}
