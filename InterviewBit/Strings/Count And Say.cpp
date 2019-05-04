/*The count-and-say sequence is the sequence of integers beginning as follows:

1, 11, 21, 1211, 111221, ...
1 is read off as one 1 or 11.
11 is read off as two 1s or 21.

21 is read off as one 2, then one 1 or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

Example:

if n = 2,
the sequence is 11.*/

string Solution::countAndSay(int A) {
    
    if(A==1)
    return "1";
    else if(A==2)
    return "11";
    else if(A==3)
    return "21";
    else if(A==4)
    return "1211";
    else if(A==5)
    return "111221";
    else
    {
        int i=5,count=1,j=0;
        string temp2="";
        string temp="111221";
        for(i=5;i<A;++i)
        {
            for(j=0;j<temp.length();++j)
            {
                if(temp[j]==temp[j+1])
                ++count;
                if(temp[j]!=temp[j+1])
                {
                    temp2=temp2+std::to_string(count)+temp[j];
                    count=1;
                }
            }
            temp=temp2;
            temp2="";
        }
        
        return temp;
        
        
    }
}
