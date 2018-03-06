Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:

	Input: 
	    5
	   / \
	  3   6
	 / \   \
	2   4   7

	Target = 9

	Output: True

Example 2:

	Input: 
	    5
	   / \
	  3   6
	 / \   \
	2   4   7

	Target = 28

	Output: False

# Solutions

I misunderstood this problem description twice
+ It is not to find one element in the ancestor, one in the descendants
+ It has to be exactly two elements to add up to k

## Basic: use an unordered_map + find the complement recursively

38 ms, it is the normal speed so not bad.

But it didn't utilize the attributes of binary search tree.(Although I don't think we should use the attribute of binary search tree at all. There is no order in the answers, we just need to find the complement of current value at each node).

## Inorder traversal to faltten the BST + use a pair of collider pointers

It uses the attribute of BST. But still O(n) time O(n) space.

## BST iterator (really long code, I have pasted it to my solution)

O(N) time O(logN) space.
