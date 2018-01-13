Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

	    1
	   / \
	  2   2
	 / \ / \
	3  4 4  3

But the following [1,2,2,null,3,null,3] is not:

	    1
	   / \
	  2   2
	   \   \
	   3    3

## Recursive solution

I made some basic mistakes in C++:

+ mistake 1 I made: for two TreeNode pointer, I cannot use p==q to decide if their value are the same!  
	+ need to use p->val and q->val !!  
+ after adding this, another problem: NULL pointer cannot point to "val" field  
	+ mistake 2: I have to make sure they both are not NULL before I could finally compare their vals  