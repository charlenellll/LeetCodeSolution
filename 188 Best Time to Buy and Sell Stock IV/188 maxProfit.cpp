// 8 ms, faster than 73.90%
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if( n <= 1 || k == 0 ) return 0;
        int maxProfit = 0;
        if( k >= n * 2 ){
            for(int i = 0; i < n-1; i++ )
                if( prices[i+1] > prices[i] )
                    maxProfit += prices[i+1] - prices[i];
            return maxProfit;
        }
        vector<int> profit(2 * k, 0 );//偶数index=i位存buy(i)，奇数位i+1存sell(i)，表示第t天及之前前有i笔buy/sell的利润
        profit[0] = -prices[0];
        profit[1] = 0;
        for(int i = 2; i < 2*k; i += 2 ) profit[i] = INT_MIN; //buy i needs lower bound when i >= 2, because buy_i likely be negtive, so INT_MIN as lowerbound makes sure max() func.
        
        for(int t = 1; t < n; t++ ){
            for(int i = 2*k-1; i >= 1; i -- ){// sell k, buy k, ..., sell 2, buy 2
                if( i % 2 == 1 ) {
                    profit[i] = max(profit[i-1] + prices[t], profit[i]); // sell i
                    maxProfit = max(maxProfit, profit[i]);
                }
                else profit[i] = max(profit[i-1] - prices[t], profit[i]); // buy i
            }
            profit[0] = max(-prices[t], profit[0]);
        }
        return maxProfit;
    }
};