// 正确拆分子问题: 返回 (Rob from 0 to n-2)和(Rob from 1 to n-1)的较大值
// 4 ms, faster than 58.86%（但其实最快的sample code跟我速度一样）
class Solution {
private:
    int robHouse(vector<int>& nums, int l, int r){//[l..r]抢劫的最大值
        vector<int> money(r-l+1, 0);//money[i]记录抢劫到nums[i+l]的最大值
        money[0] = nums[l];
        money[1] = max(nums[l], nums[l+1]); //[0..n-2]至少包含两个元素 => n >= 3
        for(int i = 2; i <= r-l; i++ )
            money[i] = max(money[i-1], money[i-2]+nums[i+l]);
        return money[r-l];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if( n == 0 ) return 0;
        if( n == 1 ) return nums[0];
        if( n == 2 ) return max(nums[0], nums[1]); //防止第8行讨论的问题！避免在第10行边界越界！
        return max(robHouse(nums, 0, n-2), robHouse(nums, 1, n-1));
    }
};


// WRONG! 自己写的一个烂解法，子问题分析不对！把house 1移动到最末尾考虑，虽然它不会和house n相邻了，但仍然没有解决house1和开头考虑的house2相邻的问题！
// 52 / 74 test cases passed.
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if( n == 0 ) return 0;
        if( n == 1 ) return nums[0];
        vector<int> money(n+1, 0); //从house2 开始DP，house1移到结尾考虑;money[i]表示到house i不考虑第一个house情况的rob最大值
        for(int i = 1; i <= n; i++ ){
            if( i == 1 ){
                money[i] = nums[i];//house 2 initialization
                if( n == 2 ) return max(nums[i], nums[0]);
            }
            else if( i == 2 ) money[i] = max(nums[i], nums[i-1]);
            else if( i < n  )
                money[i] = max(money[i-1], money[i-2] + nums[i]);
            else{ // i == n
                if( i-2 != 1 ) money[i] = max(money[i-1], money[i-2] + nums[0]);
                else money[i] = max(max(money[i-1], money[i-2]), nums[0]); //不能将money[i-2]与nums[0]相加的情况
            }
        }
        money[0] = nums[0];
        return money[n];
    }
};