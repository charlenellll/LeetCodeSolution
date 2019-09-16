Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

	Example 1:

	Input: 1->2->3->4->5->NULL
	Output: 1->3->5->2->4->NULL

	Example 2:

	Input: 2->1->3->5->6->4->7->NULL
	Output: 2->3->6->7->1->5->4->NULL

Note:

The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...

## 思路

+ 分为odd和even两路连接下去
+ 最后连接两个part

### 一个值得注意的地方

最后如果不将even list->next设置为NULL，会导致无限循环。原因：
+ 因为最后一个odd将next指针指向了第一个even元素
+ 而最后一个even元素（如果后面还有一个odd结点则）连接着最后一个odd
+ 造成了全部even元素list和最后一个odd元素的闭环