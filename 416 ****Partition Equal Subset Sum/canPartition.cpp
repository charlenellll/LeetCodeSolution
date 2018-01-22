// O(n * sum/2) = O(n * sum)

class Solution {
    
private:
    // Let memo[i][c] represent if we can use elelments in [0..i] to fill up the knapsack of size c
    // -1 unvisited; 0 false(cannot use them to fill up); 1 true.
    vector<vector<int>> memo;
    // check if we can fill up a knapsack of size sum using elements in nums[0..index]
    bool tryPartition(const vector<int>& nums, int index, int sum){
        
        if(sum == 0)
            return true;
        if( sum < 0 || index <0 )
            return false;
        if(memo[index][sum] != -1)
            return memo[index][sum] == 1;
        
        memo[index][sum] = ((tryPartition(nums, index-1, sum) || tryPartition(nums, index-1, sum-nums[index] ))? 1 : 0);
        return memo[index][sum] == 1;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            assert( nums[i] > 0 );
            sum += nums[i];
        }
        
        if( sum%2 == 1 )
            return false;
        memo = vector<vector<int>>(nums.size(), vector<int>(sum/2+1, -1));
        return tryPartition( nums, nums.size()-1, sum/2 );
    }
};