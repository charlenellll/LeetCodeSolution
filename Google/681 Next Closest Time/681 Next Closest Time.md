Given a time represented in the format "HH:MM", form the next closest time by reusing the current digits. There is no limit on how many times a digit can be reused.

You may assume the given input string is always valid. For example, "01:34", "12:09" are all valid. "1:34", "12:9" are all invalid.

Example 1:

	Input: "19:34"
	Output: "19:39"
	Explanation: The next closest time choosing from digits 1, 9, 3, 4, is 19:39, which occurs 5 minutes later.  It is not 19:33, because this occurs 23 hours and 59 minutes later.
	
Example 2:

	Input: "23:59"
	Output: "22:22"
	Explanation: The next closest time choosing from digits 2, 3, 5, 9, is 22:22. It may be assumed that the returned time is next day's time since it is smaller than the input time numerically.

# Difficulty: Medium

## Solution 1: Brutal force

从最后一位开始考虑，逐位寻找稍大的数，找到即返回。若这一位没有找到比它大的数，则将这一位变为最小数，继续前一位搜寻。

## Solution 2：upper_bound() 使上述流程能用循环遍历，简化代码

	auto it = s.upper_bound(val)

有了这个函数就不用像前面那样自己手动寻找第一个可以替代当前元素的数字了：
+ 是二分查找的一种版本，试图在已排序的[first,last)中寻找元素value：
	+ 如果[first,last)具有与value相等的元素(s),便返回一个迭代器，指向其中第一个元素；
	+ 如果没有这样的元素存在，便返回“假设这样的元素存在时应该出现的位置”，也就是说，它返回一个迭代器，指向第一个“不小于value”的元素；
	+ 如果value大于[first,last)内的任何一个元素，则返回last。
+ 另外一种理解，其返回值是“在不破坏排序状态的原则下，可插入value的第一个位置”。

# 额外的一些收获：string的操作自己确实不熟

### 1. 用+连接字符串时，至少其中之一是string类型对象；不能直接用+连接两个新字符串,因为指针不能相加（比如”abcd“+"efg"）
只能:

	string s = "abcd";
	s += "efg";

### 2. string和char可以用+号连接
但是，
+ 只能用s = s + 'a' + 'b' + 'c'; 
+ 不能用s += 'a' + 'b' + 'c';会乱码

### 3. （'0'+数字）得到的是int，需要用char转换为字符

	cout << typeid('0'+4).name();
	cout << typeid(char('0'+4)).name();
### 4. s+="a"比 s=s+"a" 快，前者是采用引用，没有产生新的对象；后者是产生新的对象，赋给s。