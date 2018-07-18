// Stack
// O(n) time O(n) space
// 0 ms
// beats 100% submissions

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int m = S.size(), n = T.size();
        stack<int> s,t;
        for(int i = 0; i < m; i++){
            if( S[i] != '#') s.push(S[i]);
            else if( s.size() > 0 ) s.pop();
        }
        for(int i = 0; i < n; i++){
            if( T[i] != '#') t.push(T[i]);
            else if( t.size() > 0 ) t.pop();
        }
        if( s.size() != t.size() ) return false;
        while(s.size() > 0 ){
            if( s.top() != t.top() ) return false;
            s.pop();
            t.pop();
        }
        return true;
    }
};