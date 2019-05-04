/*Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7  might become 4 5 6 7 0 1 2 ).

You are given a target value to search. If found in the array, return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Input : [4 5 6 7 0 1 2] and target = 4
Output : 0

NOTE : Think about the case when there are duplicates. Does your current solution work? How does the time complexity change?**/


int findPivot(const vector<int> &A){
    int start = 0;
    int end = A.size()-1;
    int mid;
    int n = A.size();
    while(start <= end){
        mid = start + (end-start)/2;
        int next = (mid+1)%n;
        int prev = (mid-1+n)%n;
        if(A[start] <= A[end]){
            return start;
        }
        else if((A[mid] <= A[prev]) && (A[mid] <= A[next])){
            return mid;
        }
        else if(A[mid] <= A[end]){
            end = mid-1;
        }
        else{ // A[mid] >= A[start]
            start = mid+1;
        }
    }
    return -1;
}

int binarySearch(const vector<int> &A, int start, int end, int key){
    int mid;
    while(start <= end){
        mid = start + (end-start)/2;
        if(A[mid] == key){
            return mid;
        }
        else if(A[mid] > key){
            end = mid-1;
        }
        else{ // A[mid] < key
            start = mid+1;
        }
    }
    return -1;
}

int Solution::search(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int pivot = findPivot(A);
    if(B == A[pivot]){
        return pivot;
    }
    
    int result = binarySearch(A, 0, pivot-1, B);
    
    if(result == -1){
        return binarySearch(A, pivot+1, A.size()-1, B);    
    }
    
    return result;
    
    // B < A[pivot]
    
}
