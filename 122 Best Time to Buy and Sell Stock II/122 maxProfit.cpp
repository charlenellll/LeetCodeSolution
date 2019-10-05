// 常见解法：当有增长就将其累加
// 4 ms, faster than 98.03%
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if( prices.size() <= 1 ) return 0;
        int maxProfit = 0;
        for(int i = 0; i < prices.size()-1; i++ )
            if( prices[i] < prices[i+1] )
                maxProfit += prices[i+1] - prices[i];
        return maxProfit;
    }
};

// 自创的解法：将问题转化为找连续递增区间；和上面的常见解法同样时间空间复杂度
// 8 ms, faster than 60.63% 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int n = prices.size();
        int p = 0;
        while( p < n-1 ){
            while( p < n-1 && prices[p] >= prices[p+1] ) p++;
            int q = p;
            while( q < n-1 && prices[q] < prices[q+1] ) q++;
            maxProfit += prices[q] - prices[p];
            p = q+1;
        }
        return maxProfit;
    }
};