Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],


	    3
	   / \
	  9  20
	    /  \
	   15   7


return its minimum depth = 2.

# Trap upon the recursive step

If a node only has one child, you cannot choose the minimum depth of children's. Instead, the depth of the only child is the only choice.