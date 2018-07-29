Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Note:

Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.
Example:

Input: root = [4,2,5,1,3], target = 3.714286

	    4
	   / \
	  2   5
	 / \
	1   3

Output: 4

## BST

### Recursion 

递归效率低是函数调用的开销导致的。在编译器不能做尾递归优化的情况下，还是应该将尾递归形式手动改成循环结构以提升性能。

### Iteration 


## Float求绝对值要用fabs()，整数求绝对值用 abs()