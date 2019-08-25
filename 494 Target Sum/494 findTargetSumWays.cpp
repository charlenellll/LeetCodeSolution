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

