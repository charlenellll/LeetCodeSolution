class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        if( n == 0 )
            return 0;
        
        vector<int> memo(n, 1);
        for(int i = 1; i < n; i++)
            // i used for(int j = n-1; j >0; j--) is the same, draw a physical model and you'll know.
            for(int j = 0; j < i; j++)
                if( nums[j] < nums[i] )
                    memo[i] = max(memo[i], 1 + memo[j]);
        
        int res = 1;
        for(int i = 0; i < n; i++)
            res = max(res, memo[i]);
        
        return res;
    }
};

// Time complexity: O(n^2)
// There is a solution with timwe complexity O(NlogN), I guess it's using mergesort.
// I will update the code using Merge Sort when I have time.