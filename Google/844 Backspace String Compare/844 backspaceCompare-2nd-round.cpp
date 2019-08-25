// I tried not using stack, but it will always be wrong
// In this case: "bxj##tw","bxo#j##tw"

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int p = S.size()-1, q = T.size()-1;
        while( p >= 0 && q >= 0 ){
            while( p >= 0 && S[p] == '#' ){
                int count = 1, i = p;
                while( i > 0 && S[i-1] == '#') count ++, i--;
                p = p - 2 * count;
            }
            while( q >= 0 && T[q] == '#' ){
                int count = 1, i = q;
                while( i > 0 && T[i-1] == '#') count ++, i--;
                q = q - 2 * count;
            }
            if( p < 0 && q < 0 ) break;
            if( (p < 0 && q >= 0) || (p >= 0 && q < 0)) return false;
            if( S[p] == T[q] ) p--, q--;
            else return false;
        }
        return true;
    }
};

// So this problem needs stack to solve!!!
// 0 ms, beats 100%
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s1, s2;
        for(int i = 0; i < S.size(); i++){
            if( S[i] == '#' && !s1.empty() ) s1.pop();
            else if(S[i] != '#') s1.push(S[i]);
        }
        for( int j = 0; j < T.size(); j++ ){
            if( T[j] == '#' && !s2.empty() ) s2.pop();
            else if(T[j] != '#') s2.push(T[j]);
        }
        if( s1.size() != s2.size() ) return false;
        while( !s1.empty() ){
            if( s1.top() != s2.top() ) return false;
            else s1.pop(), s2.pop();
        }
        return true;
    }
};