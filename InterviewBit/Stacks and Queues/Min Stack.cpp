/*Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) – Push element x onto stack.
pop() – Removes the element on top of the stack.
top() – Get the top element.
getMin() – Retrieve the minimum element in the stack.
Note that all the operations have to be constant time operations.

Questions to ask the interviewer :

Q: What should getMin() do on empty stack? 
A: In this case, return -1.

Q: What should pop do on empty stack? 
A: In this case, nothing. 

Q: What should top() do on empty stack?
A: In this case, return -1
 NOTE : If you are using your own declared global variables, make sure to clear them out in the constructor. */
 
 stack <int> S;
stack <int> S1; //Stores min

MinStack::MinStack() {
    while(!S.empty())
    S.pop();
    
    while(!S1.empty())
    S1.pop();
    
    
}

void MinStack::push(int x) {
    
    if(S1.empty() || x<=S1.top())
    S1.push(x);
    
    S.push(x);
}

void MinStack::pop() {
    if(S.empty())
        return;
        
        if(S1.top()==S.top())
        S1.pop();
        
    
    S.pop();
}

int MinStack::top() {
    
    if(S.empty())
    return -1;
    else
    return S.top();
}

int MinStack::getMin() {
    
    if(S1.empty())
    return -1;
    else
    return S1.top();
    
}

