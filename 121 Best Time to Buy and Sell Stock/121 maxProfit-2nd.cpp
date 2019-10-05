// Solution 2: 在一个指针遍历数组时，同时记录这之前经过的的最小元素 和 最大差值 O(N)且只遍历一遍
// 4 ms, faster than 98.20%
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if( prices.size() <= 1 ) return 0;
        int curMin = prices[0], maxP = 0;
        for(int i = 1; i < prices.size(); i++ ){
            curMin = min(curMin, prices[i]);
            maxP = max(maxP, prices[i] - curMin);
        }
        return maxP;
    }
};

// Solution 1: 自创的方法 虽然也是O(n)但不止遍历了一次元素，所以还是solution 2更简单
// 8 ms, faster than 65.79% 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int n = prices.size();
        int p = 0;
        while( p < n-1 ){
            while ( p < n-1 && prices[p] >= prices[p+1] ) p++;
            int q = n-1;
            while( q > p ) maxProfit = max(maxProfit, prices[q--] - prices[p]);
            p++;
        }
        return maxProfit;
    }
};