// 1. O(n)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if( n == 0 ) return 0;
        
        int sum = nums[0], maxSum = nums[0];
        for( int i = 1; i < n; i++ ){
            if( sum < 0 )
                sum = nums[i];
            else
                sum += nums[i];
            maxSum = max( sum, maxSum );
        }
        return maxSum;
    }
};


// 2. DP

//典型的动态规划问题：
//思路首先：
//很显然在连续累加的过程中，加了nums[i]如果sum是小于0的，那么说明前一次计算出的sums其副作用，需要重新寻找起始开始累加
//即重新以当前nums[i]为起始值开始累加
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];//记录累加过程中的最大值
        int subSum = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            subSum = subSum <= 0? nums[i] : subSum+nums[i];
            if(subSum > maxSum) 
                maxSum = subSum;
        }
        return maxSum;
    }
};


// sum(i) represent the maximum subarray starts from i，so the recursive equation would be:
// sum(i) = max{A[i], A[i] + sum(i+1)}

//sample 6ms solution

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int result = nums[0], sum = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            sum = max(sum + nums[i], nums[i]);
            result = max(result, sum);
        }
        return result;
    }
};