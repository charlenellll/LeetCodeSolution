Convert a BST to a sorted circular doubly-linked list in-place. Think of the left and right pointers as synonymous to the previous and next pointers in a doubly-linked list.

Let's take the following BST as an example, it may help you understand the problem better:

![image](http://assets.leetcode.com/uploads/2018/10/12/bstdlloriginalbst.png)
 
We want to transform this BST into a circular doubly linked list. Each node in a doubly linked list has a predecessor and successor. For a circular doubly linked list, the predecessor of the first element is the last element, and the successor of the last element is the first element.

The figure below shows the circular doubly linked list for the BST above. The "head" symbol means the node it points to is the smallest element of the linked list.

![image](http://assets.leetcode.com/uploads/2018/10/12/bstdllreturndll.png)

 
Specifically, we want to do the transformation in place. After the transformation, the left pointer of the tree node should point to its predecessor, and the right pointer should point to its successor. We should return the pointer to the first element of the linked list.

The figure below shows the transformed BST. The solid line indicates the successor relationship, while the dashed line means the predecessor relationship.

![image](http://assets.leetcode.com/uploads/2018/10/12/bstdllreturnbst.png) 

## Solution: recursion + pointer operations

比 剑指offer “二叉搜索树与双向链表” 这道题多了一步首尾相连的操作。

递归：函数返回一棵树经过改造后的头结点，需要进行的指针操作为：

- base case：结点为空或叶子结点则直接返回
- 左子树末尾结点->right = root，root->left = 它；（记得判断左子树的返回是否为空, 以及注意断开子树头尾连接时候的问题！）
- 右子树开头结点->left = root, root->right = 它。（同理要记得判断）
- 整棵树的尾部节点与头部节点指针连接(因为左子树和右子树返回可能为空，要分情况讨论)。