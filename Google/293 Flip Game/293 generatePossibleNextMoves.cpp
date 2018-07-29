// 1. O(n) time O(n) space
// 0 ms, beats 100%
class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> res;
        int n = s.size();
        if( n < 2 ) return res;
        int p = 0, q = 1;
        while( q < n ){
            while( !(s[p] == '+' && s[q] == '+') && q < n ) p++, q++;
            if( q < n ) res.push_back(s.substr(0, p) + "--" + s.substr(q+1));
            p++, q++;
        }
        return res;
    }
};

// 2. O(n) time O(1) space
// Optimization: change on the original string, after recorded the result, then change it back.

class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> res;
        int n = s.size();
        if( n < 2 ) return res;
        int p = 0, q = 1;
        while( q < n ){
            while( !(s[p] == '+' && s[q] == '+') && q < n ) p++, q++;
            s[p] = s[q] = '-';
            if( q < n ) res.push_back(s);
            s[p] = s[q] = '+';
            p++, q++;
        }
        return res;
    }
};


// Example code:
// O(n) time O(1) space

class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> moves;
        int n = s.length();
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '+' && s[i + 1] == '+') { 
                s[i] = s[i + 1] = '-';
                moves.push_back(s);
                s[i] = s[i + 1] = '+';
            }
        }
        return moves;        
    }
};