// 8 ms, faster than 94.42%
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        // Record the frequency of ASCII code character in the sliding window
        int freq[256] = {0};
        int l = 0, r = -1; //The sliding window is s[l...r]
        int res = 0;
        
        while(l < s.size()){
            if( r+1 < s.size() && freq[s[r+1]] == 0 ){
                freq[s[++r]] ++;
            }
            else
                freq[s[l++]] --;
            res = max(res, r-l+1);
        }
        return res;
    }
};