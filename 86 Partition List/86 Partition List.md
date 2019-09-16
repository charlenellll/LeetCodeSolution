Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example:

	Input: head = 1->4->3->2->5->2, x = 3
	Output: 1->2->2->4->3->5

## Solution 1: 直观的指针变化

但自己写的有点复杂了。

根据最直观的感觉，分为三段：
+ 已处理好的部分（即放在新的小数之前的部分）
+ 值 >= x 的部分（大part）
+ 新的小数（小part）
并做指针更改。

关于特殊情况的讨论：刚开始想起来觉得很复杂，毕竟这个solution代码中指针移动多次，可能有多种情况。
##### 结果发现只需在找大part之后判断一下当前指针（大part的后一个结点）是否指向空节点
+ 若不为空，则表明有小part
+ 若为空，表明前面是大part（包含两种情况：链表全都是大part，或前面部分是按照顺序排好的），直接返回即可。

## Solution 2： sample code, 和我的解法时间相同

应当就是简化版的我的代码，但直接看来思路比较清奇。
+ 一个节点b负责连大的，一个节点a负责连小的
+ 遍历一个个节点，判断是连a还是b
+ 最后这些部分串起来（说实话line 31没看懂