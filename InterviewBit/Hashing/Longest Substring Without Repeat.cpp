/*Given a string, 
find the length of the longest substring without repeating characters.

Example:

The longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.

For "bbbbb" the longest substring is "b", with the length of 1.*/

int Solution::lengthOfLongestSubstring(string A) {
    
    //Get a variable to store the starting of new substring
    
    int start=0;
    int len=0;
    int maxlen=INT_MIN;
    
    
    //Get a hash table to store the last occurence of the character
    
    unordered_map<char,int>M;
    
    //Now let's go!
    
    M[A[0]]=0;
    
    string substring="";
    
    int i;
    
    for(i=1;i<A.length();++i)
    {
        char c=A[i];
        
        //If this is present 
        
        if(M.find(c)!=M.end())
        {
            //Check if it is after the start
            
            if(M[c]>=start)
            {
                len=i-start;
                if(len>=maxlen)
                maxlen=len;
                
                
            
                start=M[c]+1;
                
                
                
            }
            
            M[c]=i;
        }
        
        else
        M[c]=i;
    }
    
    if(i-start>=maxlen)
        maxlen=i-start;
        
    
    
        return maxlen;

}
