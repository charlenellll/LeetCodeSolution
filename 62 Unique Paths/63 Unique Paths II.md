A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

![image](http://assets.leetcode.com/uploads/2018/10/22/robot_maze.png)

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

Example 1:

Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

## DP 对于obstacle的处理：有obstacle的格子numPath值应当为0
+ 初始化第一行和第一列的时候需要**判断自己和前一个格子是否有obstacle，不判断前一个格子直接赋值为1会出问题。**（虽然有break遇到了obstacle会跳出不再赋值为1，但不能排除(0,0)位为obstacle的情况因为循环不是从那儿开始的。）
+ DP时，当当前格子不为obstacle是加上方和左方来的path数，否则不理会（初始化这一格为0）