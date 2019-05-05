/*There are N children standing in a line. Each child is assigned a rating value.

 You are giving candies to these children subjected to the following requirements:
Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

Sample Input :

Ratings : [1 2]
Sample Output :

3
The candidate with 1 rating gets 1 candy and candidate with rating cannot get 1 candy as 1 is its neighbor. So rating 2 candidate gets 2 candies. In total, 2+1 = 3 candies need to be given out.*/

int Solution::candy(vector<int> &A) {
            
            vector <int> candies(A.size(),0);
            int sum=0;
            candies[0]=1;
            
            for(int i = 1; i<A.size(); i++) {
            if(candies[i] == 0) 
            {
                candies[i]=1;
            }
 
            if(A[i] > A[i-1])
            {
                candies[i] = candies[i-1]+1;
            }
        }
 
        
        for(int i = A.size()-1; i > 0; i--) {
            if(A[i-1] > A[i] && candies[i-1] <= candies[i]) {
                candies[i-1] = candies[i]+1;
            }
        }
            
             for(int i = 0; i < A.size(); i++) {
            sum += candies[i];
        }
        
        
        return sum;
}
