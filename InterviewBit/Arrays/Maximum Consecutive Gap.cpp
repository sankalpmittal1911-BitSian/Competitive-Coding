/*Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Example :

Input : [1, 10, 5]
Output : 5 
Return 0 if the array contains less than 2 elements.

You may assume that all the elements in the array are non-negative integers and fit in the 32-bit signed integer range.
You may also assume that the difference will not overflow.*/

void sort(vector<int> &nums, int s, int e, int d) {
        if (d < 0 || s == e)
            return;
        int i = s;
        for (int j = s; j < e; j++)
            if (nums[j] & (1 << d))
                swap(nums[i++], nums[j]);
        sort(nums, s, i, d-1);
        sort(nums, i, e, d-1);
    }
int Solution::maximumGap(const vector<int> &A) 
{
    int i,n = A.size();
    vector <int> nums(n);
    for(i=0;i<n;i++)
        nums[i] = A[i];
    sort(nums, 0, nums.size(), 31);
    int max_diff = 0;
    for (int i = 1; i < nums.size(); i++)
        max_diff = max(max_diff, nums[i-1] - nums[i]);
    return max_diff;
}
