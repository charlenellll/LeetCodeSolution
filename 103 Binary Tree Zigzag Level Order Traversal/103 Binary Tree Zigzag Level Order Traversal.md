Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],

	    3
	   / \
	  9  20
	    /  \
	   15   7
return its zigzag level order traversal as:

	[
	  [3],
	  [20,9],
	  [15,7]
	]

## Iterative way : BFS with level info

+ Do a iterative BFS
+ record the level information, level starts from 0 (root)
+ when level % 2 == 1, reverse the result of that level

## Recursive way: DFS with level info
  
+ level starts from 0
+ when level % 2 == 0, the node->val will be insert to the back of the vector<int> in that level
+ else insert to the front