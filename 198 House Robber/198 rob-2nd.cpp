// 0 ms, faster than 100.00% 
class Solution {
public:
    int rob(vector<int>& nums) {
        // money[i] represents the maximum value we can get at house i
        int n = nums.size();
        if( n == 0 ) return 0;
        if( n == 1 ) return nums[0];
        vector<int> money(n, 0);
        money[0] = nums[0];
        money[1] = max(nums[1], nums[0]);
        for(int i = 2; i < n; i++ )
            money[i] = max(money[i-1], money[i-2]+nums[i]);
        
        return money[n-1];
    }
};