Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.

## Solution 1: DP

Pac-man problem.
+ num[i]表示加起来为i的perfect square的最小个数
+ num[i] = min(1 + num[i-k·k]), k·k为perfect square ( 1 <= k·k <= i )

## Solution 2: BSF和图的最短路径！！第一次到达0的一定是最短路径

转化为图论问题：
+ 从n到0，每个数字表示一个节点
+ 如果两个数字x到y相差一个完全平方数，则连接一条边
+ 原问题转化为：求这个无权图中从n到0的最短路径。


最原始的BFS代码：

	class Solution {
	public:
	    int numSquares(int n) {
	        queue<pair<int,int>> q;//第几个数字 经过几段路径到了这个数字（最后求(0,step)）
	        q.push(make_pair(n, 0));
	        while( !q.empty() ){
	            int num = q.front().first;
	            int step = q.front().second;
	            q.pop();
	            if( num == 0 ) return step;
	            for( int k = 1; num - k*k >= 0; k++ ){
	                q.push(make_pair(num - k*k, step+1));
	            }
	        }
	        return -1;
	    }
	};

但遇到test case 7168 就会 Memory Limit Exceeded。

### BFS优化：不记录重复节点

在内部push进queue时，实际上有很多很多重复的 key为 num-k·k 的记录，因为**在无权图中可以有很多条路径到达同一节点。**

因此用一个查找表来记录这个元素是否被push进队列过，如果有过，就不往里push了。其实可以理解的是作为层序遍历，路径更短的情况下这个节点先被放入队列中，**第一次到达该点的一定是到该点的最短路径**，因为我们只关心最短路径step数，所以后面到来的其他更长的路径我们就不用记录了。

## 分析为什么BFS比DP快

+ DP实际将问题分解为子问题后，里面尝试了每种可能的分解方式。
+ BFS通过求最短路径，第一次到达0时就停止了，相当于只得到了最短路径时就提前终止。