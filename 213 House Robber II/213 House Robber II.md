You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.


	Example 1:

	Input: [2,3,2]
	Output: 3
	Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
	             because they are adjacent houses.
	Example 2:

	Input: [1,2,3,1]
	Output: 4
	Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
	             Total amount you can rob = 1 + 3 = 4.

## DP - 这道题分解子问题比较tricky！

相对于198#来说这道题多了首尾house相邻的限制，导致分解子问题比较tricky，我自己写的第一个解法就是分解问题不当！

### 这道问题的正确分解方法
（0-based index下）house 0 和 n-1 相邻，因此我们最终的返回值是：
+ Rob house 0 to n-2
+ Rob house 1 to n-1
二者中的最大值。