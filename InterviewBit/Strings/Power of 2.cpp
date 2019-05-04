/*Find if Given number is power of 2 or not. 
More specifically, find if given number can be expressed as 2^k where k >= 1.

Input:

number length can be more than 64, which mean number can be greater than 2 ^ 64 (out of long long range)
Output:

return 1 if the number is a power of 2 else return 0

Example:

Input : 128
Output : 1*/

string multiplyByTwo(string A){
    string ans = "";
    int sum = 0, carry = 0;
    for(int i = A.size()-1; i >= 0; i--){
        sum=(A[i]-'0')*2+carry;
        carry = sum/10;
        sum = sum%10;
        ans+=(sum+'0');
    }
    if(carry > 0){
        ans+=(carry+'0');
    }
    for(int i = 0; i < ans.size()/2; i++){
        char c = ans[i];
        ans[i] = ans[ans.size()-i-1];
        ans[ans.size()-i-1] = c;
    }
    
    return ans;
}

bool compareString(string temp, string num){
    if(temp.size() == num.size()){
        return temp<num;
    }
    else if(temp.size() < num.size()){
        return true;
    }
    return false;
}

int Solution::power(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i = 0;
    int length = A.size();
    while(A[i] == '0' && i < length){
        i++;
    }
    if(i == length){
        return 0;
    }
    
    string num = "";
    while(i != length){
        num = num + A[i];
        i++;
    }
    
    string temp = "2";
    while(compareString(temp, num)){
        temp = multiplyByTwo(temp);
    }
    
    if(temp == num){
        return 1;
    }
    
    return 0;
}
