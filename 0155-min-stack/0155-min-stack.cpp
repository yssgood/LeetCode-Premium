class MinStack {
public:
    stack<int> mainStack;
    stack<int> minStack; 
    MinStack() {
        
    }
    
    void push(int val) {
        mainStack.push(val); 
        if(minStack.empty() || val <= minStack.top()) minStack.push(val); 
    }
    
    void pop() {
        int top_ele = top(); 
        if(!minStack.empty() && minStack.top() == top_ele) minStack.pop(); 
        mainStack.pop(); 
    }
    
    int top() {
        return mainStack.top(); 
    }
    
    int getMin() {
        return minStack.top(); 
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */