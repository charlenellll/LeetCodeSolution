// Sliding window

// 2. 使用int array
// 4ms, beats 94.11%

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int l = 0, r = -1;
        int type[256] = {0};
        int typeCnt = 0;
        int maxNum = 0;
        while( r+1 < s.length()){
            r++;
            if( type[s[r]] == 0 ) typeCnt++;
            type[s[r]]++;
            while( typeCnt > 2 ){
                type[s[l]]--;
                if( type[s[l]] == 0) typeCnt--;
                l++;
            }
            maxNum = max(maxNum, r-l+1);
        }
        return maxNum;
    }
};

// 1. 使用map
// 8 ms, 42.3%

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int l = 0, r = -1;
        unordered_map<char, int> type;
        int maxNum = 0;
        while( r+1 < s.length()){
            r++;
            type[s[r]]++;
            while( type.size() > 2 ){
                type[s[l]]--;
                if( type[s[l]] == 0) type.erase(s[l]);
                l++;
            }
            maxNum = max(maxNum, r-l+1);
        }
        return maxNum;
    }
};