/*Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

Example :

Given numerator = 1, denominator = 2, return "0.5"
Given numerator = 2, denominator = 1, return "2"
Given numerator = 2, denominator = 3, return "0.(6)"*/

string Solution::fractionToDecimal(int A, int B) {
    
    int numerator=A;
    int denominator=B;
    
    if (numerator == 0) return "0";
    bool minus = ((numerator > 0 && denominator < 0) 
                        || (numerator < 0 && denominator > 0)) ? true  : false;
    int64_t N = abs(int64_t(numerator));
    int64_t D = abs(int64_t(denominator));
/*  
    int64_t gcd = GCD(N,D);
    N /= gcd;
    D /= gcd;
*/
    int64_t n = N/D;
    string ret;
    if (minus) ret.append("-");
    ret.append(to_string(n));
    int64_t R = N - n*D;
    if (R == 0) return ret; 
    ret.append(".");
    ssize_t dotPos = ret.length() - 1;
    int nrm = 0;
    int64_t d = D;
    n = N;
    while(n%10 == 0 && d %10 == 0) {
        n/=10;
        d/=10;
    }
    while(n%5 == 0 && d %5 == 0) {
        n/=5;
        d/=5;
    }
    while(n%2 == 0 && d %2 == 0) {
        n/=2;
        d/=2;
    }
    
    while (d%10 ==0) {
        d/=10;
        nrm++;
    }
    while (d%5==0) {
        d/=5;
        nrm++;
    }
    while (d%2==0) {
        d/=2;
        nrm++;
    }
    
    size_t pos = ret.length();
    ret.resize(pos+nrm);
    int i = 0;
    while (R > 0 && i < nrm) {
        R*=10;
        int8_t M = R / D;
        R -= M * D;
        ret[pos++] = M + '0';
        i++;
    }

    if (R == 0) return ret;

    //first pass calculate length of repeated seq
    
    int lng = 0;
    int64_t Rstart = R;
    
    do {
        R*=10;
        R -= (R / D) * D;
        lng++;
    } while (Rstart != R);
    
    ret.resize(pos+lng+2);
    ret[pos++] = '(';
    while (lng-- > 0) {
        R*=10;
        int64_t M = R / D;
        R -= M * D;
        ret[pos++] = M + '0';
    }
    ret[pos] = ')';
    return ret;
}
