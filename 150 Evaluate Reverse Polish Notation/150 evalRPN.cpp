// 12 ms, faster than 89.57% 
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i = 0; i < tokens.size(); i++ ){
            string curStr = tokens[i];
            if( curStr == "+" || curStr == "-" || curStr == "*" || curStr == "/"){
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                int res;
                switch( curStr[0] ){
                    case '+':
                        res = a + b;
                        break;
                    case '-':
                        res = a - b;
                        break;
                    case '*':
                        res = a * b;
                        break;
                    case '/':
                        res = (int)(a / b);
                        break;
                }
                s.push(res);
            }
            else
                s.push(stoi( curStr ));
        }
        return (s.empty()) ? 0 : s.top();
    }
};