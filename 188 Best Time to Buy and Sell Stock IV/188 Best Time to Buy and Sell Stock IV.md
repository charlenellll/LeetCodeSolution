Say you have an array for which the i-th element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

	Example 1:
	
	Input: [2,4,1], k = 2
	Output: 2
	Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
	Example 2:
	
	Input: [3,2,6,5,0,3], k = 2
	Output: 7
	Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
	             Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.

## DP

受到123#的启发，每个buy1, buy2, sell1, sell2, ... buy k, sell k 等等都可以用一个int记录，因此只需要一个长度为2k（注意k的范围）的数组来记录这2k种状态值。（解法详解可以看123#）

依赖关系是 sell k =依赖=> buy k ==> sell k-1 ==> buy k-1 ==> ... sell 1 ==> buy 1。因此设计数组的时候按照这样的顺序排列方便更新。从sell k先更新，到buy 1为止。

### 注意特殊情况处理: 当2\*k >= nums.size(), 退化为122#

有一个test case k = 10亿，而输入没有那么多天，很明显建立2\*k的数组会使程序异常退出。

而且其实只要当 2\*k >= nums.size()  时，本题退化为122号题，即可进行任意次交易。