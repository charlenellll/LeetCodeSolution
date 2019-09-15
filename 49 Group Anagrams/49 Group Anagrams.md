
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.

# Map

The idea is simple, but the difficulty is medium because of the tricky part: 

## C++ set和map的键值限制: set或map的key使用自定义类型时必须重载<关系运算符

C++ map的键类型可以是一个类，比如键类型可以是C\++标准库中的string类，但是对作为键的类有一个约束，那就是这个类必须定义小于操作符，也就是要重载小于运算操作符（C++标准库的string类就定义了小于操作符）。而且这个小于操作符比较函数还必须符合“严格弱排序”，简单来说就是：与自身比较时返回false，当两个键对象不存在小于关系，就视为相等；k1小于k2，k2小于k3，则k1必然小于k3。

# Solution 2 for this problem:

Because we cannot use a structure as:

	unordered_map<unordered_map<char, int>, vector<string>> record;

### The tricky part is how to design a suitable search table

We can **sort the strings** and use:

	unordered_map<string, vector<string>> record;

### Solution 1 in the 2nd round code: Use 2 temp map to store the current pair of strs to be compared

This method TLE on the last test case, so please choose solution 2 to pass all test cases.

Using sort() is tricky and smart in solution 2.