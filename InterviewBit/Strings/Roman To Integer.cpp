/*Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

Read more details about roman numerals at Roman Numeric System

Example :

Input : "XIV"
Return : 14
Input : "XX"
Output : 20*/

int Solution::romanToInt(string A) {
    
    int val1=0,val2=0;
    int i,result=0;
    for(i=0;i<A.length();++i)
    {
        switch(A[i])
        {
            case 'I': 
            val1=1;
            break;
            
            case 'V':
            val1=5;
            break;
            
            case 'X':
            val1=10;
            break;
            
            case 'L':
            val1=50;
            break;
            
            case 'C':
            val1=100;
            break;
            
            case 'D':
            val1=500;
            break;
            
            case 'M':
            val1=1000;
            break;
            
        }
        if(i+1<A.length())
        {
        switch(A[i+1])
        {
            case 'I': 
            val2=1;
            break;
            
            case 'V':
            val2=5;
            break;
            
            case 'X':
            val2=10;
            break;
            
            case 'L':
            val2=50;
            break;
            
            case 'C':
            val2=100;
            break;
            
            case 'D':
            val2=500;
            break;
            
            case 'M':
            val2=1000;
            break;
            
        }
        
        if(val1>=val2)
        result=result+val1;
        else
        {
        result=result+val2-val1;
        ++i;
        }
        //cout<<result<<" ";
        }
        else
        {
           result=result+val1;
           ++i;
        }
        
    }
    return result;
}
