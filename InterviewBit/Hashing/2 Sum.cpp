/*Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 < index2. Please note that your returned answers (both index1 and index2 ) are not zero-based. 
Put both these numbers in order in an array and return the array from your function ( Looking at the function signature will make things clearer ). Note that, if no pair exists, return empty list.

If multiple solutions exist, output the one where index2 is minimum. If there are multiple solutions with the minimum index2, choose the one with minimum index1 out of them.

Input: [2, 7, 11, 15], target=9
Output: index1 = 1, index2 = 2*/

vector<int> Solution::twoSum(const vector<int> &arr, int target) {
    unordered_map<int, int> hmap;  
    int size = arr.size();
    for(int i=0 ; i<size ; ++i) {
        auto get = hmap.find(target - arr[i]);
        // return the vector if we found 2 numbers
        if(get != hmap.end())   return vector<int>{get->second, i+1};
        
        // add the element if its not a duplicate
        if(hmap.find(arr[i]) == hmap.end())     hmap[arr[i]] = i+1;   
    }
    return vector<int>{};
}
