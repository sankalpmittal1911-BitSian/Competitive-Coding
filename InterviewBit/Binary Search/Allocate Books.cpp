/*N number of books are given. 
The ith book has Pi number of pages. 
You have to allocate books to M number of students so that maximum number of pages alloted to a student is minimum. A book will be allocated to exactly one student. Each student has to be allocated at least one book. Allotment should be in contiguous order, for example: A student cannot be allocated book 1 and book 3, skipping book 2.

NOTE: Return -1 if a valid assignment is not possible

Input:

List of Books
M number of students
Your function should return an integer corresponding to the minimum number.

Example:

P : [12, 34, 67, 90]
M : 2

Output : 113

There are 2 number of students. Books can be distributed in following fashion : 
  1) [12] and [34, 67, 90]
      Max number of pages is allocated to student 2 with 34 + 67 + 90 = 191 pages
  2) [12, 34] and [67, 90]
      Max number of pages is allocated to student 2 with 67 + 90 = 157 pages 
  3) [12, 34, 67] and [90]
      Max number of pages is allocated to student 1 with 12 + 34 + 67 = 113 pages

Of the 3 cases, Option 3 has the minimum pages = 113.*/

bool isPossible(vector <int> arr, int n, int m, int curr_min) 
{ 
    int studentsRequired = 1; 
    int curr_sum = 0; 
  
    // iterate over all books 
    for (int i = 0; i < n; i++) 
    { 
        // check if current number of pages are greater 
        // than curr_min that means we will get the result 
        // after mid no. of pages 
        if (arr[i] > curr_min) 
            return false; 
  
        // count how many students are required 
        // to distribute curr_min pages 
        if (curr_sum + arr[i] > curr_min) 
        { 
            // increment student count 
            studentsRequired++; 
  
            // update curr_sum 
            curr_sum = arr[i]; 
  
            // if students required becomes greater 
            // than given no. of students,return false 
            if (studentsRequired > m) 
                return false; 
        } 
  
        // else update curr_sum 
        else
            curr_sum += arr[i]; 
    } 
    return true; 
} 




int Solution::books(vector<int> &A, int B) {
    
    
    long long sum = 0; 
  
    // return -1 if no. of books is less than 
    // no. of students 
    if (A.size() < B) 
        return -1; 
  
    // Count total number of pages 
    for (int i = 0; i < A.size(); i++) 
        sum += A[i]; 
  
    // initialize start as 0 pages and end as 
    // total pages 
    int start = 0, end = sum; 
    int result = INT_MAX; 
  
    // traverse until start <= end 
    while (start <= end) 
    { 
        // check if it is possible to distribute 
        // books by using mid as current minimum 
        int mid = (start + end) / 2; 
        if (isPossible(A, A.size(), B, mid)) 
        { 
            // if yes then find the minimum distribution 
            result = min(result, mid); 
  
            // as we are finding minimum and books 
            // are sorted so reduce end = mid -1 
            // that means 
            end = mid - 1; 
        } 
  
        else
            // if not possible means pages should be 
            // increased so update start = mid + 1 
            start = mid + 1; 
    } 
  
    // at-last return minimum no. of  pages 
    return result; 
}
