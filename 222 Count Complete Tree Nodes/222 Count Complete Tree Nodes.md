Given a complete binary tree, count the number of nodes.

Note:

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Example:

	Input: 
	    1
	   / \
	  2   3
	 / \  /
	4  5 6

	Output: 6

## Solution 1: Brutal force

DFS O(N) time O(logN) space - system stack 
BFS O(N) time O(N) space