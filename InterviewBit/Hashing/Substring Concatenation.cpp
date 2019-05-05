/*You are given a string, S, and a list of words, L, that are all of the same length.

Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

Example :

S: "barfoothefoobarman"
L: ["foo", "bar"]
You should return the indices: [0,9].
(order does not matter).*/

vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    
    //Lets create a Map
    
    int xLen=B[0].length()*B.size();
    
    vector <int> start_ind;
    
    
    unordered_map<string,int>M;
    
    int i,flag=0;
    string temp="";
    
    for(i=0;i<B.size();++i)
        ++M[B[i]];
    
    
    if(A.length()<xLen)
    return start_ind;
    
    for(i=0;i<A.length()-xLen+1;++i)
    {
        unordered_map<string,int> M1(M);
        
        for(int j=i;j<i+xLen;j+=B[0].length())
        {
            temp=A.substr(j,B[0].length());
            
            if(M.find(temp)!=M.end())
            --M1[temp];
            else
            break;
        }
        
        flag=0;
        
        for(auto it=M1.begin();it!=M1.end();++it)
        {
            if(it->second>0)
            {
            flag=1;
            break;
            }
        }
        
        if(flag==0)
        start_ind.push_back(i);
    }
        
        
       return start_ind;
    
    
}
