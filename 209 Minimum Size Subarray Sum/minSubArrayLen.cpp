class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        // Set nums[l,r] as the sliding window     
        int l = 0, r = -1;
        int sum = 0;
        int res = nums.size() + 1;
        
        while(l < nums.size()){
            if(r+1 < nums.size() && sum < s)
                sum += nums[++r];
            else // If r+1 is out of boundary, we can only slide l index
                sum -= nums[l++];
            if(sum >= s)
                res = min(res, r-l+1);
        }
        
        if(res == nums.size() + 1)
            return 0;
        
        return res;
    }
};