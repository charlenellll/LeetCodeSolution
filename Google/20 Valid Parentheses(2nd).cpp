// O(N) Time, O(1) Space
// 0 ms, beats 100%

class Solution {
private:
    stack<char> record;
    bool isPair(char a, char b){
        switch(a){
            case '}':
                return b == '{'; break;
            case ')':
                return b == '('; break;
            case ']':
                return b == '['; break;
            default:
                return false; break;
        }
    }
public:
    bool isValid(string s) {
        int n = s.size();
        for(int i = 0; i < n; i++){
            if( record.size() != 0 ){
                char c = record.top();
                if( !isPair(s[i], c) ) record.push(s[i]);
                else record.pop();
            }
            else record.push(s[i]);
        }
        return record.size() == 0;
    }
};