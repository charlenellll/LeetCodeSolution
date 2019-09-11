// Optimization on S2: use vector to replace map
// 8 ms, faster than 86.60% 
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if( s.size() != t.size() ) return false;
        vector<int> s2i(256,0); //ASCII code has 256 members
        vector<int> t2i(256,0);
        for(int i = 0; i < s.size(); i++){
            if( s2i[s[i]] != t2i[t[i]] )
                return false;
            s2i[s[i]] = t2i[t[i]] = i+1;
        }
        return true;
    }
};

// Solution 2: for these 1-to-1 relationship problems, code can be more concise if you map letter/words to the last index they show up
// the maps are 1-based since if one element does not exist in the map, map[element] = 0 will be set defaultly by the code.
// 12 ms, faster than 51.15%
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if( s.size() != t.size() ) return false;
        unordered_map<char, int> s2i;
        unordered_map<char, int> t2i;
        for(int i = 0; i < s.size(); i++){
            if( s2i[s[i]] != t2i[t[i]] )
                return false;
            s2i[s[i]] = t2i[t[i]] = i+1;
        }
        return true;
    }
};

// Solution 1: brutal force, map characters to words, words to characters
// 12 ms, faster than 51.15%

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if( s.size() != t.size() ) return false;
        unordered_map<char, char> s2t;
        unordered_map<char, char> t2s;
        for(int i = 0; i < s.size(); i++){
            if( s2t.find(s[i]) != s2t.end() ){
                if( s2t[s[i]] != t[i] )
                    return false;
            }
            else
                s2t[s[i]] = t[i];
            if( t2s.find(t[i]) != t2s.end() ){
                if( t2s[t[i]] != s[i] )
                    return false;
            }
            else
                t2s[t[i]] = s[i];
        }
        return true;
    }
};