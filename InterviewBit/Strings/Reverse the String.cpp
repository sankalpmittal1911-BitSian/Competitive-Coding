/*Given an input string, reverse the string word by word.

Example:

Given s = "the sky is blue",

return "blue is sky the".

A sequence of non-space characters constitutes a word.
Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.
If there are multiple spaces between words, reduce them to a single space in the reversed string.*/

void Solution::reverseWords(string &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    
    string word,ans="";
    vector<string> v(0);
    for(int i=0;i<A.size();i++){
        if(A[i]!=' '){
            word+=A[i];
        }
        if((i==A.size()-1 || (A[i]==' ' && A[i+1]!=' ')) && word.size()>0){
            v.emplace_back(move(word));
            word="";
        }
    }
    reverse(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
        ans+=v[i];
        if(i!=v.size()-1)ans+=" ";
    }
   A=ans;
    
}
