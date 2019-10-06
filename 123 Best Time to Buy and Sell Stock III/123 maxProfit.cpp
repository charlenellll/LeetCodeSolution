// 细节方法二：先理清依赖关系，sell2依赖buy2依赖sell依赖buy1依赖自己，因此从sell2开始改
// 4 ms, faster than 98.39%
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if( n <= 1 ) return 0;
        int buy1 = -prices[0], sell1 = 0, buy2 = INT_MIN, sell2 = INT_MIN;// buy1:在第i天及其之前共只进行了一笔buy的利润，其余同理
        for(int i = 1; i < n; i++ ){//注意更新用到的记录是谁！
            sell2 = max(buy2 + prices[i], sell2);
            buy2 = max(sell1 - prices[i], buy2);
            sell1 = max(buy1 + prices[i], sell1);
            buy1 = max( -prices[i], buy1);
        }
        return max(0, max(sell1, sell2));
    }
};
// 细节方法一：每次计算新值时全部计算完毕再覆盖，防止在数备用前修改掉(不过这样多了一些不必要的操作)
// 8 ms, faster than 71.52%, in the majority
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if( n <= 1 ) return 0;
        int buy1 = -prices[0], sell1 = 0, buy2 = INT_MIN, sell2 = INT_MIN;// buy1:在第i天及其之前共只进行了一笔buy的利润，其余同理
        for(int i = 1; i < n; i++ ){//注意更新用到的记录是谁！
            int new_buy1 = max( -prices[i], buy1);
            int new_buy2 = max(sell1 - prices[i], buy2);
            int new_sell1 = max(buy1 + prices[i], sell1);
            int new_sell2 = max(buy2 + prices[i], sell2);
            buy1 = new_buy1, buy2 = new_buy2, sell1 = new_sell1, sell2 = new_sell2;
        }
        return max(0, max(sell1, sell2));
    }
};