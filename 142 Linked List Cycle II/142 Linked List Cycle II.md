Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

Note: Do not modify the linked list.

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.


Example 2:

Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.


Example 3:

Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.

## Solution 1: 自己想的办法 O(N) Extra space

原始想法：记录slow指针每次走过的节点并记录它的index和它的上一个节点指针。当fast指针第一次遇到slow指针记录过的节点时，我们所求的节点可能是这个节点/这个节点的上一个节点，只有这两种情况。如何判断该返回哪一个呢？

我进行了分情况讨论，列出实例，展示了四种情况，分别是 环外节点个数 和 环包含节点个数：奇偶，偶奇，偶偶，奇奇 四种情况。其中当环外节点数 + 环包含节点数 为奇数时fast指针停的位置是我们所求节点的后一个结点；为偶数时fast指针停在的节点即为所求节点。

最后发现其实 环外节点数 + 环包含节点数 = tail节点的index+1（节点的编号是0-based）

其实转变成了：
+ 1. 移动快慢指针，当fast指针第一次遇到被slow指针经过的节点时停下；
+ 2. slow指针继续一个个移动直到找到tail
+ 3. 根据tail的index判断该返回fast指针（index+1==偶数）还是它前面的元素（index+1==奇数）
	+ 有一个特例！当fast指针指向的元素self-loop时，不应当返回它之前的那个元素（因为是在它进入loop前记录的），也就判断一下fast是不是自循环（即fast->next==fast），若是，则不管奇数还是偶数都直接返回fast即可。

这个方法比较慢因为我用了一个hash map。

+ 当然没有环时记得判断

复盘后这个解法有一个问题：这和用一个指针移动并记录经过的节点，然后当第一个重复节点出现即我们所求节点，是一样的。也就是说，我其实完全没有用到fast指针的信息！

## Solution 2: 从e点往前走到我们所求节点的距离 = 从head走到所求点的距离 O(1) extra space

+ 先移动fast和slow指针直到二者相遇，记这个pointer叫e
+ 新定义一个指针叫h，从head开始，和e同步一个个向右移动
+ 当h和e二者相遇时即是我们所求点

可以通过fast与slow相遇点fast所走距离是slow的两倍 + 画图证明，从e点往前走到我们所求节点的距离 = 从head走到所求点的距离。

+ 当然要记得判断没有环的时候
