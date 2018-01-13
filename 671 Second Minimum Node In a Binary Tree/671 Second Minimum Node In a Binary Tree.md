Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes.

Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.

If no such second minimum value exists, output -1 instead.

Example 1:

	Input: 
	    2
	   / \
	  2   5
	     / \
	    5   7

	Output: 5
	Explanation: The smallest value is 2, the second smallest value is 5.
Example 2:

	Input: 
	    2
	   / \
	  2   2

	Output: -1
	Explanation: The smallest value is 2, but there isn't any second smallest value.

## Recursively

The value of the root is the smallest value in the tree, now we just need to find the smallest value in the tree other than the nodes having the same value as the root.

So in the recursive function, we have to pass in the value of the root into it.  
minVal == root->val;

In the recursive function:
+ we check if the node's value == minVal
+ if not, return node->val
+ if so, try to find the answer in its left and right subtree
	+ if both its subtree have value that's second smallest value other than minVal, we take the smaller one
	+ if any of its subtree returns -1 (only has minVal or has no subtree), take the larger one
		+ if both the subtrees consists of minVal, it will return -1

## solution 2: use a set

It's not as efficient as pruned recursion. It will traverse all nodes.

	int findSecondMinimumValue2(TreeNode* root) {
	    set<int> vals;
	    stack<TreeNode*> nodes;
	    nodes.push(root);
	    while (!nodes.empty()) {//BFS
	        TreeNode* node = nodes.top();
	        nodes.pop();
	        vals.insert(node->val);
	        if (node->left)
	            nodes.push(node->left);
	        if (node->right)
	            nodes.push(node->right);
	    }
	    set<int>::iterator it = vals.begin();
	    if (vals.size() > 1)//取第二个元素
	        return *(++it);
	    else
	        return -1;
	}