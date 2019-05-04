/*Please Note:
Note: It is intended for some problems to be ambiguous. You should gather all requirements up front before implementing one.

Please think of all the corner cases and clarifications yourself.

Validate if a given string is numeric.

Examples:

"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Clarify the question using “See Expected Output”

Is 1u ( which may be a representation for unsigned integers valid?
For this problem, no.
Is 0.1e10 valid?
Yes
-01.1e-10?
Yes
Hexadecimal numbers like 0xFF?
Not for the purpose of this problem
3. (. not followed by a digit)?
No
Can exponent have decimal numbers? 3e0.1?
Not for this problem.
Is 1f ( floating point number with f as prefix ) valid?
Not for this problem.
How about 1000LL or 1000L ( C++ representation for long and long long numbers )?
Not for this problem.
How about integers preceded by 00 or 0? like 008?
Yes for this problem*/

bool checkNumber(string A, int i){
    
    while(isspace(A[i])){
        i++;
    }
    
    if(i == A.size()){
        return 0;
    }
    
    while(isspace(A[A.size()-1])){
        A.pop_back();
    }
    
    int eflag = 0;
    int sflag = 0;
    int dflag = 0;
    int nflag = 0;
    
    while(i < A.size()){
        if(isdigit(A[i])){
            i++;
            nflag = 1;
        }
        else{
            if(A[i] == 'e'){
                if(nflag == 0){
                    return 0;
                }
                eflag = 1;
                sflag = 0;
                dflag = 0;
                nflag = 0;
                i++;
                if(i == A.size()){
                    return 0;
                }
            }
            else if(A[i] == '+' || A[i] == '-'){
                i++;
                if(i == A.size()){
                    return 0;
                }
                if(sflag == 0){
                    sflag = 1;
                }
                else{
                    return 0;
                }
                if(nflag == 0){
                    sflag = 1;
                }
                else{
                    return 0;
                }
            }
            else if(A[i] == '.'){
                if(dflag == 0){
                    dflag = 1;
                }
                else{
                    return 0;
                }
                if(eflag == 1){
                    return 0;
                }
                nflag = 1;
                i++;
                if(i == A.size()){
                    return 0;
                }
                else if(!isdigit(A[i])){
                    return 0;
                }
            }
            else{
                return 0;
            }
        }
    }
    
    return 1;  
}




int Solution::isNumber(const string A) {
    return checkNumber(A, 0);
}
