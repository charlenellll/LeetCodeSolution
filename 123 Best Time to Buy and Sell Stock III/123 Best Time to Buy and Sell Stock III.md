Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

	Example 1:
	
	Input: [3,3,5,0,0,3,1,4]
	Output: 6
	Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
	             Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
	Example 2:
	
	Input: [1,2,3,4,5]
	Output: 4
	Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
	             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
	             engaging multiple transactions at the same time. You must sell before buying again.
	Example 3:
	
	Input: [7,6,4,3,1]
	Output: 0
	Explanation: In this case, no transaction is done, i.e. max profit = 0.

## DP

限制条件：做 <= 2次交易。

设buy1[i]表示到第i天为止以一笔buy交易结尾的利润。buy2, sell1, sell2 同理：
+ buy1[i] = max( 0 - prices[i], buy[i-1]); 分别表示是在第i天进行的第一笔buy交易，和在第i天之前完成了一笔buy交易
+ buy2[i] = max( sell1[i-1] - prices[i], buy2[i-1]);
+ sell1[i] = max(buy1[i-1] + prices[i], sell1[i-1]);
+ sell2[i] = max(buy2[i-1] + prices[i], sell2[i-1]);

本来想用四个数组来进行DP，但这里观察可得，每个数组第i时刻只需要第i-1时刻的数据，因此这四个的每一个都可以就用一个int记录。

当然注意值之间的依赖关系，别在它被用到之前改了它。