Given a binary tree where all the right nodes are either leaf nodes with a sibling (a left node that shares the same parent node) or empty, flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes. Return the new root.

For example:
Given a binary tree {1,2,3,4,5},

	    1
	   / \
	  2   3
	 / \
	4   5
return the root of the binary tree [4,5,2,#,#,3,1].

	   4
	  / \
	 5   2
	    / \
	   3   1  

# Tree

**The tricky part of this problem: how to model this problem?**

This original tree is left-leaning.

After fliping, the leftmost leave will be the new root, its parent will become its right child, and its right sibling will become its left child.

There are three ways to model this problem:

## 1. Recursive (postorder DFS)

The most obvious way is to divide this problem into finish flipping the left subtree and do the job recursively. 

Each recursion will return the new root of the left subtree, and we can do the pointer operation in a DFS process. The recursive function will naturally find the leftmost node.

// 2. Iterative

// In OJ it is not more efficient. And really tricky to think of.