/*Given a string S and a string T, find the minimum window in S which will contain all the characters in T in linear time complexity.
Note that when the count of a character C in T is N, then the count of C in minimum window in S should be at least N.

Example :

S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC"

 Note:
If there is no such window in S that covers all characters in T, return the empty string ''.
If there are multiple such windows, return the first occurring minimum window ( with minimum start index ).*/

const int no_of_chars = 256; 



string Solution::minWindow(string S, string T) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int len1 = S.length(); 
    int len2 = T.length(); 
  
    // check if string's length is less than pattern's 
    // length. If yes then no such window can exist 
    if (len1 < len2) 
    { 
        
        return ""; 
    } 
  
    unordered_map<char,int>hast_pat;
    unordered_map<char,int>hast_str;
    
   // int hash_pat[no_of_chars] = {0}; 
    //int hash_str[no_of_chars] = {0}; 
  
    // store occurrence ofs characters of pattern 
    for (int i = 0; i < len2; i++) 
        hash_pat[T[i]]++; 
  
    int start = 0, start_index = -1, min_len = INT_MAX; 
  
    // start traversing the string 
    int count = 0; // count of characters 
    for (int j = 0; j < len1 ; j++) 
    { 
        // count occurrence of characters of string 
        hash_str[S[j]]++; 
  
        // If string's char matches with pattern's char 
        // then increment count 
        if (hash_pat[S[j]] != 0 && 
            hash_str[S[j]] <= hash_pat[S[j]] ) 
            count++; 
  
        // if all the characters are matched 
        if (count == len2) 
        { 
            // Try to minimize the window i.e., check if 
            // any character is occurring more no. of times 
            // than its occurrence in pattern, if yes 
            // then remove it from starting and also remove 
            // the useless characters. 
            while ( hash_str[S[start]] > hash_pat[S[start]] 
                || hash_pat[S[start]] == 0) 
            { 
  
                if (hash_str[S[start]] > hash_pat[S[start]]) 
                    hash_str[S[start]]--; 
                start++; 
            } 
  
            // update window size 
            int len_window = j - start + 1; 
            if (min_len > len_window) 
            { 
                min_len = len_window; 
                start_index = start; 
            } 
        } 
    } 
  
    // If no window found 
    if (start_index == -1) 
    { 
    
    return ""; 
    } 
  
    // Return substring starting from start_index 
    // and length min_len 
    return S.substr(start_index, min_len); 
    
}
