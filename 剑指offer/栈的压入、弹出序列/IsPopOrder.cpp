// 精简版逻辑:每次都不判断直接push进去，看能否引发pop操作
// 运行时间：3ms 占用内存：612k
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if( pushV.size() != popV.size() ) return false;
        stack<int> simulate;
        int n = pushV.size(), p = 0;
        for(int i = 0; i < n; i++ ){
            simulate.push( pushV[i] ); // 此元素需要入栈
            while( !simulate.empty() && p < n && simulate.top() == popV[p] ){// 是否可能此时出栈
                simulate.pop();
                p++; // i不变，当前元素还没有入栈
            }
        }
        return simulate.empty();
    }
};

// 直观逻辑
// 运行时间：4ms 占用内存：468k
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if( pushV.size() != popV.size() ) return false;
        stack<int> simulate;
        int n = pushV.size(), p = 0;
        for(int i = 0; i < n; i++ ){
            if( pushV[i] == popV[p] ) p++;// 一入栈一出栈，直接i++ p++
            else{ // 二者不匹配
                while( !simulate.empty() && p < n && simulate.top() == popV[p] ){// 1.不匹配可能因为此时出栈
                    simulate.pop();
                    p++; // i不变，当前元素还没有入栈
                }
                simulate.push( pushV[i] ); // 2.此元素需要入栈
            }
        }
        while( p < n && simulate.top() == popV[p] ){
            simulate.pop();
            p++;
        }
        return simulate.empty();
    }
};