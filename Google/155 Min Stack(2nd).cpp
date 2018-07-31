// 16 ms, beats 98.23%
// 所有操作 O(1) time，O(n) space
// 关键点是用最小值stack，存储历史最小值及其copy

class MinStack {
private:
    stack<int> s;
    stack<int> minS;
public:
    /** initialize your data structure here. */
    MinStack() {
        s = stack<int>();
        minS = stack<int>();
    }
    
    void push(int x) {
        s.push(x);
        if( minS.empty() || x <= minS.top() ) minS.push(x);
    }
    
    void pop() {
        if( minS.top() == s.top() ) minS.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minS.top();
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