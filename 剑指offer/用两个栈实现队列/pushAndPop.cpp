// 运行时间：3ms 占用内存：476k
class Solution
{
public:
    void push(int node) {
        while( !stack2.empty() ){
            stack1.push(stack2.top());
            stack2.pop();
        }
        stack1.push(node);
    }

    int pop() {
        while( !stack1.empty() ){
            stack2.push(stack1.top());
            stack1.pop();
        }
        int ret = stack2.top();
        stack2.pop();
        return ret;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};