Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

	Input:
	[
	  [1,3,1],
	  [1,5,1],
	  [4,2,1]
	]
	Output: 7
	Explanation: Because the path 1→3→1→1→1 minimizes the sum.

## DP

	建立mxn表格minSum，表示到（i,j）位置处的最小sum。
	+ minSum[0][0] = grid[0][0]
	+ minSum[i][0] = minSum[i-1][0] + grid[i][0], minSum[0][j] = minSum[0][j-1] + grid[0][j]
	+ minSum[i][j] = grid[i][j] + min(minSum[i-1][j], minSum[i][j-1]) when i > 0 && j > 0