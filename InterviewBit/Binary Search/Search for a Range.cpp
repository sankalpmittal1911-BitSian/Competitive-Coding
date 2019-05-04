/*Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm’s runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example:

Given [5, 7, 7, 8, 8, 10]

and target value 8,

return [3, 4].*/

vector<int> Solution::searchRange(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector <int> pos;
    int high=A.size()-1,low=0,result=-1;
    int mid=0;
    while(low<=high)
    {
        mid=low+(high-low)/2;
        if(A[mid]==B)
        {
            result=mid;
            high=mid-1;
        }
        else if(A[mid]>B)
        high=mid-1;
        else
        low=mid+1;
    }
    if(result==-1)
    {
        pos.push_back(-1);
        pos.push_back(-1);
        return pos;
    }
    int firstindex=result;
    high=A.size()-1;
    low=0;
    result=-1;
    mid=0;
    while(low<=high)
    {
        mid=low+(high-low)/2;
        if(A[mid]==B)
        {
            result=mid;
            low=mid+1;
        }
        else if(A[mid]>B)
        high=mid-1;
        else
        low=mid+1;
    }
    
    int lastindex=result;
    pos.push_back(firstindex);
    pos.push_back(lastindex);
    return pos;
    
    
}
