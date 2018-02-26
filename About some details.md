Leetcode 387:

如 n = 12,尝试用int record[26] = {n}初始化数组将每个元素设为12，发现只有第一个是12，剩余都是0：

## C++ int数组初始化问题！

int record[26] = {n}; 只有第一个为n，其余都是0！！！
int record[26];		  没有进行初始化，每一位都是物理地址原来存储的数字，随机
int record[26] = {0}; 将record[0]初始化为一个指定数字（为了与剩余数字统一，将其初始化为0），而剩余元素自动初始化为0！

### 所以要使用“int record[26] = {0}”和“记录index为实际index+1”的组合！

记录index为实际index+1：  
是为了避免index=0和初始值相同的顾虑！用i+1表示实际的i，避免判断和初始值相同时发生错误，最后返回时对i+1进行-1后返回i.

---

Leetcode 141

## 从物理上判断两个对象是不是同一个对象，而不是值

我一开始竟然想不出来这道题除了快慢指针的简单做法，即O(n) space的做法，因为如果链表里有很多重复值的话，不能用set确保找到环。

后来看了分析才茅塞顿开！天啊！明明是面向对象的，我为什么要用值来判断两个对象是否相等？

要从物理上判断2个对象是否相等，用 == 就可以了。或者用指针，也是指向对象本身，可以通过比较指针知道它们是不是物理上的同一个对象。

因此只要用一个装着ListNode\*的set就OK！

---

Leetcode 771 Jewels and Stones:

#### 不要满目使用int数组

==**要先思考int数组和unordered_set哪个更适合当前环境before use it！**==

不要盲目地条件反射用int数组替代set！！！用之前一定要想想这么用会不会更好！！！

## 什么时候用int数组替代set？

满足两个条件：

### 1. 当key有序并且需要这个信息的时候，unordered_set不能满足功能需求，int array比set快！

unordered_set不能满足这个需求，不能按照键值的顺序遍历。而set时间是O(logn),比不上int数组的O(1).

==其实只要对key的顺序没有要求，就全都可以用unordered_set!==

下列附加要求是为了防止自己犯傻。

### 2. (附加判断条件，防止犯傻) 如果对key的顺序没有需求：当int数组不比unordered_set容量大的时候

而这道题里J长度<=50，如果用int数组，对于有大小写的letter容量必须要256或稍微小一丢丢来容纳它们。因为ASCII码里A-Z和a-z之间有别的字符，总之这个一定比unordered_set大，故用unordered_set更快！这里别用int数组！！

## 慎用string对象里面的find()系列函数

**find()的实现不是linear time**! Be careful when you use it!

The C++ standard doesn't specify implementation details, and only specifies complexity requirements in some cases. The only complexity requirements on std::string operations are that size(), max_size(), operator[], swap(), c_str() and data() are all constant time. **The complexity of anything else depends on the choices made by whoever implemented the library you're using.** 

所以说，string类除了以上指定的函数以外，其余所有函数没有复杂度要求，也就是说，复杂度完全依赖于你用的库的实现！

而业界几乎没有用KMP算法（O(M+N)）的string类内find()函数，最坏的话它的实现可能是O(M * N)的！

### 什么时候能用find()函数：查找字符串

这道题里，我们只一个一个字符地找，明明用hash table只要O(1)每次（共O(M))，用find()硬生生拖慢了！

