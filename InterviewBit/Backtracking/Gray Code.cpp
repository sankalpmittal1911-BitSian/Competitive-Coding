/*The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
There might be multiple gray code sequences possible for a given n.
Return any such sequence.*/

vector<int> Solution::grayCode(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
                int p = pow(2, A);
              vector<int> s(p);
              if (A > 1){
                     vector<int> v = grayCode(A-1);
                
                     int i_tmp = pow(2,A-1);
                     for (int i = 0; i < p; i++)
                     {
                           if (i < p / 2)
                           {
                                  s[i] = v[i];
                           }
                           else{
                                  s[i] = i_tmp + v[p - 1 - i];
                           }
                     }
                     return s;
              }
              else if (A == 1){
                     s[0] = 0;
                     s[1] = 1;
                     return s;
              }
              else {
                     s[0] = 0;
                     return s;
              }
}
