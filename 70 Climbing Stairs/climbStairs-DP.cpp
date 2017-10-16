class Solution {
private:
    vector<int> memo;
    
public:
    int climbStairs(int n) {
        memo = vector<int>(n+1,-1);
        
        memo[0] = 1;
        memo[1] = 1;
        for(int i = 2; i <= n; i++)
                memo[i] = memo[i-1] + memo[i-2];
        return memo[n];
    }
};

// Use dynamic programming: bottom-up