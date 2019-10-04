Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:

    2
   / \
  1   3

Input: [2,1,3]
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.

## 子问题分解

Binary Search Tree的特点：左子树所有值（严格）小于root，右子树所有值（严格）大于root。

递归过程可以分为四个部分：
+ left child < root, right child > root
+ 左子树是valid BST
+ 右子树是valid BST
+ 最后一步容易被忽略：**判断边界值：左子树的最大值 < root，右子树的最小值 > root**