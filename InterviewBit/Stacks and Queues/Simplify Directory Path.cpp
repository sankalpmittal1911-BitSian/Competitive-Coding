/*Given an absolute path for a file (Unix-style), simplify it.

Examples:

path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
Note that absolute path always begin with ‘/’ ( root directory )
Path will not have whitespace characters.*/

string Solution::simplifyPath(string A) {
    
    string res="/";
    string temp;
    stack <string> S;
    int flag=0;
    for(int i=0;i<A.length();++i)
    {
        
        temp="";
        
        while(A[i]=='/')
        ++i;
        
        
        
        while(i<A.length() && A[i]!='/')
        {
        temp.push_back(A[i]);
        ++i;
        }
        
        if(temp.compare(".")==0)
        continue;
        
        else if(temp.compare("..")==0)
        {
            if(!S.empty())
            S.pop();
        }
        
        else if(temp.length()!=0)
            S.push(temp);
        
        
        
    }
    
    stack <string> S1;
    while(!S.empty())
    {
        S1.push(S.top());
        S.pop();
    }
    
    while(!S1.empty())
    {
        if(S1.size()!=1)
        res.append(S1.top()+"/");
        else
        res.append(S1.top());
        S1.pop();
    }
    
    

    if(res.compare("")==0)
    res="/";
    
    return res;
}
