class MinStack {
private:
    stack<int> s;
    stack<int> minStack;
public:
    /** initialize your data structure here. */
    MinStack() {
        s = stack<int> ();
        minStack = stack<int> ();
    }
    
    void push(int x) {
        s.push(x);              // "=" is important when there are multiple copies of x been pushed onto stack
        if( minStack.empty() || x <= minStack.top() )
            minStack.push(x);
    }
    
    void pop() {
        if( s.top() == minStack.top() ){
            minStack.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */