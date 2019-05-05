/*Given an array of size n, find the majority element. The majority element is the element that appears more than floor(n/2) times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example :

Input : [2, 1, 2]
Return  : 2 which occurs 2 times which is greater than 3/2. */

public class Solution {
    // DO NOT MODIFY THE ARGUMENTS WITH "final" PREFIX. IT IS READ ONLY
    public int majorityElement(final int[] A) {
        
        int l,B[],i;
        l=A.length;
        B=new int [A.length];
        for(i=0;i<l;++i)
        B[i]=0;
        for(i=0;i<l;++i)
            ++B[A[i]];
        for(i=0;i<l;++i)
        {
            if(B[i]>Math.floor(l/2))
                return A[i];
        }
        
        return -1;
    }
}

//Moore's Voting Algo is the better solution
