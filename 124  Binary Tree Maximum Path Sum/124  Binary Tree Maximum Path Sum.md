Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

	Example 1:

	Input: [1,2,3]

	       1
	      / \
	     2   3

	Output: 6
	Example 2:

	Input: [-10,9,20,null,null,15,7]

	   -10
	   / \
	  9  20
	    /  \
	   15   7

	Output: 42

Difficulty: hard.

## Recursion

类似于337#，一个函数返回多个值表示（包含/不包含）根结点的情况。

Tricky part: 实际上路径的连通，需要函数返回三种情况：
+ 包含根结点：
	+ 根结点连接单边
	+ 根结点连接双边（这种情况下，外层计算包含当前根结点的路径时，就不能加包含孩子结点并且它连接了双边的情况）
+ 不包含根结点

限制条件主要在于：根结点与孩子结点的maxValue path连接时，孩子结点只能连接单边，孩子连通双边grandchild的值不能与根结点连接。

所以三种情况要分开讨论。