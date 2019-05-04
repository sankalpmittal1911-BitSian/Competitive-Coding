/*Compare two version numbers version1 and version2.

If version1 > version2 return 1,
If version1 < version2 return -1,
otherwise return 0.
You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 1.13 < 1.13.4*/

int compareSubstr(char *substr_version1, char *substr_version2, 
                  int len_substr_version1, int len_substr_version2) 
 { 
     
     if (len_substr_version1 > len_substr_version2)  
        return 1; 
  
     else if (len_substr_version1 < len_substr_version2)  
        return -1; 
  
     else
     { 
        int i = 0, j = 0; 
  
        
        while (i < len_substr_version1) 
        { 
            if (substr_version1[i] < substr_version2[j]) return -1; 
            else if (substr_version1[i] > substr_version2[j]) return 1; 
            i++, j++; 
        } 
        return 0; 
     } 
 } 


int Solution::compareVersion(string A, string B) {
    
    int len_version1 = A.length(); 
    int len_version2 = B.length(); 
  
    char *substr_version1 = (char *) malloc(sizeof(char) * 1000); 
    char *substr_version2 = (char *) malloc(sizeof(char) * 1000);     
  
    
    int i = 0, j = 0; 
    while (i < len_version1 || j < len_version2) 
    { 
        int p = 0, q = 0; 
  
       
        while (A[i] == '0' || A[i] == '.')  
           i++; 
  
        
        while (B[j] == '0' || B[j] == '.')  
           j++; 
  
        
        while (A[i] != '.' && i < len_version1)         
            substr_version1[p++] = A[i++]; 
        
        while (B[j] != '.' && j < len_version2)         
            substr_version2[q++] = B[j++];     
  
        int res = compareSubstr(substr_version1,  
                                substr_version2, p, q); 
  
        
        if (res) 
            return res; 
    } 
  
    
    return 0; 
}
