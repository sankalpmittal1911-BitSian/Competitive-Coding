/*Given a string s, partition s such that every string of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["a","a","b"]
    ["aa","b"],
  ]
 Ordering the results in the answer : Entry i will come before Entry j if :
len(Entryi[0]) < len(Entryj[0]) OR
(len(Entryi[0]) == len(Entryj[0]) AND len(Entryi[1]) < len(Entryj[1])) OR
*
*
*
(len(Entryi[0]) == len(Entryj[0]) AND … len(Entryi[k] < len(Entryj[k]))
In the given example,
["a", "a", "b"] comes before ["aa", "b"] because len("a") < len("aa")*/

bool isPalindrome(string s){
    int n=s.length();
    for(int i=0;i<n/2;i++)
        if(s[i]!=s[n-1-i])
            return 0;
    return 1;
}
void partition1(vector<vector<string>> &v,vector<string> &row,string &s,int l,int n){
    if(l==n){
        v.push_back(row);
        return;
    }
    string temp="";
    for(int i=l;i<n;i++){
        temp.push_back(s[i]);
        if(isPalindrome(temp)){
            row.push_back(temp);
            partition1(v,row,s,i+1,n);
            row.pop_back();
        }
    }
}
vector<vector<string> > Solution::partition(string A) {
  vector<vector<string> > ans;
  vector<string> row;
  partition1(ans,row,A,0,A.length());
  return ans;
}
