// 4 ms, faster than 99.36% 
// 3. Int array !
// Notice that for int array, we should consider all possible characters, not just alphabetic ones
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int record[128] = {0};
        int l = 0, r = -1, len = 0;
        while( l < s.size() ){
            if( r+1 < s.size() && record[s[r+1]] == 0 ) {
                record[s[++r]] ++;
                len = max(len, r-l+1);
            }
            else{
                record[s[l]]--;
                l++;
            }
        }
        return len;
    }
};


// 28 ms, faster than 39.17%
// 2. Unordered_set
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> record;
        int l = 0, r = -1, len = 0;
        while( l < s.size() ){
            if( r+1 < s.size() && record.find(s[r+1]) == record.end() ) {
                record.insert(s[++r]);
                len = max(len, r-l+1);
            }
            else{
                record.erase(s[l]);
                l++;
            }
        }
        return len;
    }
};

// 32 ms, faster than 33.22%
// 1. I should not use unordered_map, at most I could use unordered_set

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> record;
        int l = 0, r = -1, len = 0;
        while( l < s.size() ){
            if( r+1 < s.size() && record.find(s[r+1]) == record.end() ) {
                record[s[++r]]++;
                len = max(len, r-l+1);
            }
            else{
                record[s[l]]--;
                if( record[s[l]] == 0 ) record.erase(s[l]);
                l++;
            }
        }
        return len;
    }
};