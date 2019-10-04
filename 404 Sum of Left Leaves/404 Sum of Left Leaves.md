Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.

## 分解子过程

+ 判断当前左child是否是叶子，若是，则加上它的value
+ 加上左子树的左叶子之和
+ 加上右子树的左叶子之和