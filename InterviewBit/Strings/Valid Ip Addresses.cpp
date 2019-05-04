/*Given a string containing only digits, restore it by returning all possible valid IP address combinations.

A valid IP address must be in the form of A.B.C.D, where A,B,C and D are numbers from 0-255. The numbers cannot be 0 prefixed unless they are 0.

Example:

Given “25525511135”,

return [“255.255.11.135”, “255.255.111.35”]. (Make sure the returned strings are sorted in order)*/

vector<string> Solution::restoreIpAddresses(string A) {
    
    vector <string> ans={};
    if(A.length()<=2 || A.length()>12)
    return {};
    if(A.length()==12)
    {
        string s1=A.substr(0,3);
        string s2=A.substr(3,6);
        string s3=A.substr(6,9);
        string s4=A.substr(9,12);
        int n1=stoi(s1);
        int n2=stoi(s2);
        int n3=stoi(s3);
        int n4=stoi(s4);
        if(n1>255 || n2>255 || n3>255 || n4>255)
        return {};
        else
        {
            ans.push_back(s1+"."+s2+"."+s3+"."+s4);
            return ans;
        }
    }
    
    int i,j,k;
    string s="";
    for(i=1;i<A.length()-1;++i)
    {
        for(j=i+1;j<A.length()-1;++j)
        {
            for(k=j+1;k<A.length();++k)
            {
                if(i<=3 && j-i<=3 && k-j<=3 && A.length()-k<=3)
                {
                string s1=A.substr(0,i);
                string s2=A.substr(i,j-i);
                string s3=A.substr(j,k-j);
                string s4=A.substr(k,A.length()-k);
                //cout<<s1<<" "<<s2<<" "<<s3<<" "<<s4;
                int n1=stoi(s1);
                int n2=stoi(s2);
                int n3=stoi(s3);
                int n4=stoi(s4);
                if(n1>255 || n2>255 || n3>255 || n4>255 || n1<0 || n2<0 || n3<0 || n4<0)
                continue;
                else
                {
                    if(!((s1[0]=='0' && s1.length()>1) || (s2[0]=='0' && s2.length()>1) || (s3[0]=='0' && s3.length()>1) || (s4[0]=='0' && s4.length()>1)))
                    
                    ans.push_back(s1+"."+s2+"."+s3+"."+s4);
                }
                }
                
            }
            
        }
    }
    return ans;
}
