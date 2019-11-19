Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

	Example:

	Input: [1,2,3,null,5,null,4]
	Output: [1, 3, 4]
	Explanation:

	   1            <---
	 /   \
	2     3         <---
	 \     \
	  5     4       <---

### 几种错误思路

1. the rightmost path
2. 记录longest path；记录rightmost path, 并覆盖同长度的元素

实际应该是所有可能路径里面取最右侧显现出来的元素。


解题思路有两种：

## BFS: Queue

O(log N) space, O(N) time

+ 层序遍历
+ 取每一层的最后一个元素

## DFS: Recursion

O(log N) system stack + O(log N) space for result, O(N) time

在recursion中：
+ 本步的操作是，如果当前level比已记录的路径长，则记录本元素（共用一个vector用于记录path输出）
+ 先recursion右子树
+ 再recursion左子树（如果没有右子树路径长则被直接忽略，不会覆盖路径上的元素）