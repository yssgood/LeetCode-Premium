class MinStack {

    Deque<Integer> mainStack = new ArrayDeque<>(); 
    Deque<Integer> minStack = new ArrayDeque<>();

    public MinStack() {
        
    }
    
    public void push(int value) {
        mainStack.addLast(value); 
        if(minStack.isEmpty() || minStack.peekLast() >= value){
            minStack.addLast(value); 
        }
    }
    
    public void pop() {
        int target = mainStack.pollLast(); 
        if(!minStack.isEmpty() && minStack.peekLast() == target) minStack.pollLast(); 
    }
    
    public int top() {
        return mainStack.peekLast(); 
    }
    
    public int getMin() {
        return minStack.peekLast(); 
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(value);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */