

# Solution

目前对于杨辉三角形的生成就目前这种方法普遍。看code好好记忆。

但是我的code速度不一样，揭露了一个问题：

## C++ 中对于 可变向量 a += b 比 a = a + b 效率高！（对于不可变向量是一样的！）

So far, the solution is the only one, but based on the detail, my soluitons can still vary in speed: see the code.

### 简单原理解释：

a += b直接在a中加了b。

a = a + b则是用一个临时变量temp记录a的值，类似过程:

	temp = a;
	temp +=b;
	a = temp;
	多了一次2次拷贝

### 为什么对于可变向量有这个差异而不可变向量没有呢？

知乎解答：https://www.zhihu.com/question/20114936

"+=" 操作调用__iadd__方法，没有该方法时，再尝试调用__add__方法。
+ \__iadd__方法直接在原对象a1上进行更新，该方法的返回值为None。

"+" 操作调用__add__方法
+ \__add__方法会返回一个新的对象，原对象不修改

+ 对于不可变对象，根本没有__iadd__方法，所以+=和+的效果是一样的，因为调的都是__add__ 方法

### Conclution: 无论什么情况都可以尽量不用 a = a + b, 用 a += b 代替它 !!