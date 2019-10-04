Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:

Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

## Solution 1: memoizing

+ 开辟（n, n）的空间，只使用下三角，记录经过三角形当前位置的路径的最小值（即选它上一行相邻的累加和较小的一个累加）；
+ 返回memo[0]\[0]

O(N^2) Space

## Solution 2: DP

+ 开辟n大小的vector，记录从最后一行开始累加的这一行中当前位置最小值（从最后一行往上累加的优点：下面的行数目更大，网上加保证不会越界，从上往下有越界问题）
+ 最开始n个元素为最后一行的n个元素
+ 依次往上求通过当前行当前col位置的最小值，即triangle[row]\[col]和（vector中相邻的从下往上累积和[col]与\[col+1]）中较小值的和，覆盖vector\[col]的位置
+ vector\[0]即为所求最终sum