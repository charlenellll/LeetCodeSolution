The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

**Example 1:**

	Input: [3,2,3,null,3,null,1]

	     3
	    / \
	   2   3
	    \   \ 
	     3   1

	Output: 7 
	Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.

**Example 2:**

	Input: [3,4,5,1,3,null,1]

	     3
	    / \
	   4   5
	  / \   \ 
	 1   3   1

	Output: 9
	Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.

## Recursion

首先，虽然例题里给的例子是隔层求和，会以为和BFS有关，其实不是！！！并不是整层整层求和然后求不相邻层的最大值！！！

问题可以分解为：maxValue(root) = max（必含root的最大值，不含root的最大值）

所以子问题里每次都求含root的最大值和不含root的最大值，为了方便返回不用vector，可以直接用int的reference传入函数得到。


### 注意求不含root的最大值时不要省了nl+nr! 

因为输入里有结点为0  or（il + nr, ir + nl, il + ir, nl+nr）这四种情况里有二者相等，这样具体选择谁会影响上层结构，所以nl+nr也是可以被单独选择的（而不要想当然一定和root一起更大！也许不选root就能选到root的parent值更大呢！）