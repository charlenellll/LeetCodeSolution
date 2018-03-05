Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

**Note:**
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

**Hint:**
Could you do it in-place with O(1) extra space?

## Solutions

There are so many solutions.

Summary of C++ solutions: https://leetcode.com/problems/rotate-array/discuss/54277/Summary-of-C++-solutions

In my code, only my 4-th solution is qualified for the O(n) time O(1) space requirement.


由于我的代码速度非常蹊跷，于是探究了一番：

# C++ vector的底层原理和操作时间复杂度

C++ vector各操作的时间复杂度：
+ push_back() 一次的均摊时间复杂度是O(1)（均摊的是reallocation的时间）
+ insert(): O(n)

## insert()的时间复杂度O(n) （连续向尾部插入N个元素，均摊时间复杂度O(1)）

为什么是线性的O(n)而不是常量O(1)呢？

假设我在大小为n的 std :: vector< mytype> 中的第i个位置插入了p个新元素。

由于 std :: vector 保证为其元素使用连续的存储位置，所以需要执行4步操作：
+ 1）如果我们的空间不足，可能重新分配向量，一般使其大小加倍。但是这是一个常数时间运算（尽管是一个非常大的运算）.
+ 2）从旧向量的索引0到i-1的元素memcpy到新向量.
+ 3）然后你复制p个新元素，插入第i个索引。
+ 4）从旧向量把从i + 1到n的所有项目memcpy到新向量。

其中：
+ memcpy 和 memmove 的时间复杂度是线性的。
	+ 因为正在移动的 k 字节中的每一个都需要正好被遍历一次，所以正在移动的块的大小为 sizeof（T）* N ，这使得时序也是线性的。
+ 即使在向量的末尾处添加一个元素，也具有线性复杂度，这是在重新分配时（上述第一步）复制数据所需要的开销；（然而，向向量的末尾添加 N 个元素的话，线性复杂性将会被均摊，这意味着摊销后的复杂度对于每个元素是常量的）。

## push_back()的均摊时间复杂度O(1)

vector的push_back()虽然在内存不足的时候会重新申请内存，但它申请内存是预先申请原来多一倍的空间，所以**很多时候均是直接往内存里面写数据即可(平均下来，插入一个元素的时间复杂度是O(1))**，效率非常高。

## 本题还可以使用reverse(),对N个元素的vector（或任何可迭代对象）复杂度O(n)

C++参考手册，std::reverse: http://classfoo.com/ccby/article/cNTmfl

由于我对它的参数一直不熟，记录一下：

	两个参数：first，last

	分别指向被反转序列中初始及末尾位置的双向迭代器（Bidirectional iterators）。
	这个范围即 [first,last) ，包括 first 到 last 间的所有元素，包括 first 指向的元素，但不包括 last 指向的元素。


## STL vector的内部实现原理及基本用法

一个归纳得不错的blog：http://blog.csdn.net/u012658346/article/details/50725933