/*Given two binary strings, return their sum (also a binary string).

Example:

a = "100"

b = "11"
Return a + b = “111”.*/

string Solution::addBinary(string A, string B) {
    
     int l1=A.length();
     int l2=B.length();
   string res="";
   int carry=0;
   if(l1<=l2)
   {
       for(int i=1;i<=l2-l1;++i)
        A='0'+A;
   }
   else
   {
       for(int i=1;i<=l1-l2;++i)
        B='0'+B;
   }
   
   //cout<<A.length()<<" "<<B.length();
   
   for(int i=A.length()-1;i>=0;--i)
   {
       if(A[i]=='1' && B[i]=='1')
       {
           if(carry==1)
           {
               res='1'+res;
               carry=1;
           }
           else if(carry==0)
           {
               res='0'+res;
               carry=1;
           }
       }
       else if((A[i]=='1' && B[i]=='0') || (A[i]=='0' && B[i]=='1' ))
       {
           if(carry==1)
           {
               res='0'+res;
               carry=1;
           }
           else if(carry==0)
           {
               res='1'+res;
               carry=0;
           }
       }
       
       else if(A[i]=='0' && A[i]=='0')
       {
           if(carry==1)
           {
               res='1'+res;
               carry=0;
           }
           else if(carry==0)
           {
               res='0'+res;
               carry=0;
           }
       }
   }
   
   //remove trailing zeroes
   int i,ind=0;
 
   for(i=0;i<res.length();++i)
   {
       if(res[i]=='1')
       {
       ind=i;
       break;
       }
   }
    res=res.substr(ind,res.length()-ind);
    if(carry==0)
    return res;
    else
    return '1'+res;
}
