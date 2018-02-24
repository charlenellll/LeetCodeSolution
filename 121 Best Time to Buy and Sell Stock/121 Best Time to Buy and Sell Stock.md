Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example 1:

	Input: [7, 1, 5, 3, 6, 4]
	Output: 5

	max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
Example 2:

	Input: [7, 6, 4, 3, 1]
	Output: 0

	In this case, no transaction is done, i.e. max profit = 0.

# Solution - don't think too much!

Since the input is not in order, it is impossible to use collider pointer. (Leetcode 11 can use it even though the input is not ordered, but it is a special case since the container's volumn always depends on the smaller edge, which makes it a hidden rule that: always move the smaller edge towards the larger edge to find possible larger edge than itself).

## Traverse the input once - find the smallest element so far and largest difference at the same time

The trick for this problem is to think simple.

What I need?
+ the smallest element **I've met so far**
+ the largest difference **I have so far**

We can get these information in one pass.