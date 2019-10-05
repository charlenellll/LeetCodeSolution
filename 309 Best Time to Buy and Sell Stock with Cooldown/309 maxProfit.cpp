// 4 ms, faster than 74.13%
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if( n <= 1 ) return 0;
        vector<int> buy(n, 0);// buy[i]表示最近以buy结束的，到第i天(0-based)的收益
        vector<int> sell(n, 0); // sell[i]表示以sell结束的，到第i天的收益
        buy[0] = -prices[0];
        sell[0] = 0;
        buy[1] = max(buy[0], -prices[1]);
        sell[1] = max(sell[0], buy[0]+prices[1]);
        for(int i = 2; i < n; i++){
            buy[i] = max(sell[i-2] - prices[i], buy[i-1]);//第i天买了(至少在i-2天及之前卖了)和第i天没买
            sell[i] = max( buy[i-1] + prices[i], sell[i-1] );//第i天卖了(至少在i-1天前买了)和第i天没卖
        }
        return sell[n-1];//buy[n-1]一定比sell[n-1]小，buy一定买了
    }
};