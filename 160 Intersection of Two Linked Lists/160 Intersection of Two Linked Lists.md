Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in **O(n) time and use only O(1) memory**.

## Solution

我的第一个解法太过于直接，以至于有很多不必要的判断。认真思考一下，可以发现优化后的思路是：

### 重点：怎么移动链表上的指针

哪一条链表的指针往后移，并没有办法指定，但是指针的移动是有规律的：

+ 两个链表后面融为一体，说明相交后的长度是相同的。
+ 所以两条链表向着长度相同而努力

所以，
1. 首先需要对每条链表遍历一遍，知道其长度
2. 向着长度相同而努力，这里优化好了的话会快一些，（可以对比我的原始方案）优化后的方案为：
	+ 先不要急着将两条链表一起动，先将两条链表长度变成一样
	+ 即把长的一条链表指针往后移至两条链表长度相同
	+ 然后一起移动，遇到相同点即为相交点，返回它
	+ otherwise返回NULL
