/*Given two integers n and k, return all possible combinations of k numbers out of 1 2 3 ... n.

Make sure the combinations are sorted.

To elaborate,

Within every entry, elements should be sorted. [1, 4] is a valid entry while [4, 1] is not.
Entries should be sorted within themselves.
Example :
If n = 4 and k = 2, a solution is:

[
  [1,2],
  [1,3],
  [1,4],
  [2,3],
  [2,4],
  [3,4],
]
 Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING COMBINATIONS.
Example : itertools.combinations in python.
If you do, we will disqualify your submission retroactively and give you penalty points. */

void combineHelper(vector<int> &current, int A, int B, vector<vector<int> > &ans) {
if (B == 0) {
vector<int> newEntry = current; 
reverse(newEntry.begin(), newEntry.end());
ans.push_back(newEntry);
return;
}
if (A == 0 || A < B) return;

combineHelper(current, A - 1, B, ans);
current.push_back(A);
combineHelper(current, A - 1, B - 1, ans);
current.pop_back();
return;
}



vector<vector<int> > Solution::combine(int A, int B) {
    vector<vector<int> > ans; 
vector<int> current;
combineHelper(current, A, B, ans);
sort(ans.begin(), ans.end());
return ans;
}




