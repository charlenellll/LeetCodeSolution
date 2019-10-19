// 运行时间：7ms 占用内存：492k
class Solution {
private:
    stack<int> s;
    stack<int> minS;// min stack
public:
    void push(int value) {
        s.push(value);
        if( minS.empty() || value < minS.top() )
            minS.push(value);
    }
    void pop() {
        if( minS.top() == s.top() )
            minS.pop(); //最新的元素不可能在里层，不用遍历
        s.pop();
    }
    int top() {
        return s.top();
    }
    int min() {
        return minS.top();
    }
};