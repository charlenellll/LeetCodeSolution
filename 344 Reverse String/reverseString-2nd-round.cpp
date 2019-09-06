// After the problem is revised
// 44 ms, faster than 92.03% 
class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0, r = s.size()-1;
        while( l < r ) swap(s[l++], s[r--]);
    }
};

// Before the problem is revised
// 8 ms, faster than 81.20% of C++ online submissions
class Solution {
public:
    string reverseString(string s) {
        int l = 0, r = s.size()-1;
        while( l < r ) swap( s[l++], s[r--]);
        return s;
    }
};