// 0 ms, faster than 100.00%
class Solution {
public:
    bool isValid(string s) {
        stack<char> remain;
        unordered_map<char, char> pair;
        pair[')'] = '(';
        pair[']'] = '[';
        pair['}'] = '{';
        for(int i = 0; i < s.size(); i++){
            if( pair.find(s[i]) == pair.end() ) //左括号
                remain.push(s[i]);
            else{ // 右括号
                if( remain.empty() || remain.top() != pair[s[i]] ) return false;// 不匹配
                else remain.pop(); //匹配
            }
        }
        return remain.empty();
    }
};