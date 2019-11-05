// 40 ms, faster than 44.96%
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if( n <= 1 ) return n;
        vector<int> len(n, 1); // len[i] means length of LIS at index i
        int maxLen = 1;
        for(int i = 1; i < n; i++ ){
            for(int j = 0; j < i; j++ )
                if( nums[j] < nums[i] )
                    len[i] = max(len[i], len[j] + 1);
            maxLen = max(maxLen, len[i]);
        }
        return maxLen;
    }
};