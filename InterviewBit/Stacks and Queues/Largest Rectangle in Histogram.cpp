/*Given n non-negative integers representing the histogram’s bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

Largest Rectangle in Histogram: Example 1

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

Largest Rectangle in Histogram: Example 2

The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.*/

int Solution::largestRectangleArea(vector<int> &A) {
    
    int i=0,tp,area,max_area=0;
    stack <int> S;
    
    
   while(i<A.size())
   {
       if(S.empty() || A[S.top()]<=A[i])
       S.push(i++);
   
   
   else
        { 
            tp = S.top();  
            S.pop();   
  
            
            area = A[tp] * (S.empty() ? i :  
                                   i - S.top() - 1); 
  
            
            if (max_area < area) 
                max_area = area; 
        } 
   }
  
    
    while (S.empty() == false) 
    { 
        tp = S.top(); 
        S.pop(); 
        area = A[tp] * (S.empty() ? i :  
                                i - S.top() - 1); 
  
        if (max_area < area) 
            max_area = area; 
    } 
  
    return max_area; 
} 
