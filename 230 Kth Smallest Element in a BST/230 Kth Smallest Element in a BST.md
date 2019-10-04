Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Example 1:

Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1
Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

## 子问题分解

+ 先count左子树节点个数（开始想的是分别知道左右子树有多少节点，后面发现只需要左边已足够）
+ root节点是第a+1大的元素，如果k==a+1则找到
+ 若 k > a+1 则在右子树找第（k-a-1）小的元素
+ 若 k < a+1 则在左子树找第k小的元素