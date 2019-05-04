/*Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Examples:

  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6*/
  
  int Solution::evalRPN(vector<string> &A) {
    
    stack <string> S;
    string op2="",op1="";
    
    for(int i=0;i<A.size();++i)
    {
        
            if(A[i].compare("*")==0)
            {
            if(S.empty())
            return -1;
            op2=S.top();
            S.pop();
            if(S.empty())
            return -1;
            op1=S.top();
            S.pop();
            S.push(to_string(stoi(op1)*stoi(op2)));
            }
            
            
            else if(A[i].compare("/")==0)
            {
            if(S.empty())
            return -1;
            op2=S.top();
            S.pop();
            if(S.empty())
            return -1;
            op1=S.top();
            S.pop();
            S.push(to_string(stoi(op1)/stoi(op2)));
            }
            
            
            else if(A[i].compare("-")==0)
            {
            if(S.empty())
            return -1;
            op2=S.top();
            S.pop();
            if(S.empty())
            return -1;
            op1=S.top();
            S.pop();
            S.push(to_string(stoi(op1)-stoi(op2)));
            }
            
            else if(A[i].compare("+")==0)
            {
            if(S.empty())
            return -1;
            op2=S.top();
            S.pop();
            if(S.empty())
            return -1;
            op1=S.top();
            S.pop();
            S.push(to_string(stoi(op1)+stoi(op2)));
            }
            
            else if(A[i].compare(",")==0)
            continue;
            
            else 
            S.push(A[i]);
           
        }
    
    
    return stoi(S.top());
    
    
}
