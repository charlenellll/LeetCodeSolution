// 196 ms, faster than 52.33% of C++ online submissions
// not strictly DP
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        unordered_map<int, int> sum; // sum at time i stores possible total sum of the integers
        sum[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            unordered_map<int,int> new_sum;
            for(auto iter: sum){
                new_sum[iter.first+nums[i]]+=iter.second;
                new_sum[iter.first-nums[i]]+=iter.second;
            }
            sum = new_sum;
        }
        return sum[S];
    }
};

// 和上面那个解法思路差不多，但空间复杂度更大，根本没必要把pos和neg分开，也没必要保留每一步的map，完全可以覆盖掉
// 256 ms, faster than 43.99% 
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        vector<unordered_map<int, int>> pos(n, unordered_map<int,int>());
        vector<unordered_map<int, int>> neg(n, unordered_map<int,int>());
        pos[0][nums[0]] = 1;
        neg[0][-nums[0]] = 1;
        for(int i = 1; i < n; i++ ){
            for(auto item: pos[i-1]){
                pos[i][item.first + nums[i]] +=  item.second;
                neg[i][item.first - nums[i]] +=  item.second;
            }
            for(auto item: neg[i-1]){
                pos[i][item.first + nums[i]] +=  item.second;
                neg[i][item.first - nums[i]] +=  item.second;
            }
        }
        return pos[n-1][S] + neg[n-1][S];
    }
};