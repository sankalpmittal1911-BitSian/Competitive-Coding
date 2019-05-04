/*Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

 Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
Example : 
Given array S = {1 0 -1 0 -2 2}, and target = 0
A solution set is:

    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
    (-1,  0, 0, 1)
Also make sure that the solution set is lexicographically sorted.
Solution[i] < Solution[j] iff Solution[i][0] < Solution[j][0] OR (Solution[i][0] == Solution[j][0] AND ... Solution[i][k] < Solution[j][k])*/

vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    vector<vector <int>> res;
    vector<int>p;
    p.resize(4);
    for(int i=0;i<A.size()-3;i++){
        if(i>0 && A[i]==A[i-1]) continue;
        for(int j=i+1;j<A.size()-2;j++){
            if(j>i+1 && A[j]==A[j-1]) continue;
            int target=B-A[i]-A[j];
            p[0]=A[i];
            p[1]=A[j];
            
            int k=j+1;
            int q=A.size()-1;
            while(k<q){
                
                int sum=A[k]+A[q];
                if(sum==target){
                    p[2]=A[k];
                    p[3]=A[q];
                    res.push_back(p);
                    while(p[2]==A[k] && k<q) k++;
                   
                }
                else if(sum<target) k++;
                else     q--;
                
            }
            
            
           
        }
        
    }
  
    return res;
    
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
