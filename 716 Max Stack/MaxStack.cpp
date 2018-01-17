class MaxStack {
private:
    stack<int> s;
    stack<int> maxs;
public:
    /** initialize your data structure here. */
    MaxStack() {
        s = stack<int> ();
        maxs = stack<int> ();
    }
    
    void push(int x) {
        s.push(x);
        if( maxs.empty() || x >= maxs.top() )
            maxs.push(x);
    }
    
    int pop() {
        int ret = s.top();
        if( ret == maxs.top() )
            maxs.pop();
        s.pop();
        return ret;
    }
    
    int top() {
        return s.top();
    }
    
    int peekMax() {
        return maxs.top();
    }
    
    int popMax() {
        int ret = maxs.top();
        if( ret == s.top() ) s.pop(), maxs.pop();
        // this part is most important part
        else{
            stack<int> temp;
            while( s.top() != ret ){
                temp.push(s.top());
                s.pop();
            }
            s.pop(), maxs.pop();
            while( !temp.empty() ){
                push( temp.top() );
                temp.pop();
            }
        }
        return ret;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */