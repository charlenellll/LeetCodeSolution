Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

	s = "leetcode"
	return 0.

	s = "loveleetcode",
	return 2.
**Note:**  
You may assume the string contain only lowercase letters.

## we have to do it in 2 pass

See the code to see the optimizations starting from brutal force.

### 1. Brutal force: unordered_map + 2 pass of input

+ unordered_map to record the count
+ traverse twice to find the first element with count 1

### 2. optimization 1: use int array + 2 pass of input

+ since this problem says "contain only lowercase letters", int array is more efficient

### 3. optimization 2: use 2 int array (1 for count 1 for index recording) + 2 pass(1 on input 1 on array)

+ the second pass only take O(26) = O(1) time

### 4. optimization 3: use 1 int array recording count and index information + 2 pass(1 on input 1 on array) 高级操作

See the code.

I've encountered a problem:  

如 n = 12,尝试用int record[26] = {n}初始化数组将每个元素设为12，发现只有第一个是12，剩余都是0：

# C++ int数组初始化问题！

int record[26] = {n}; 只有第一个为n，其余都是0！！！
int record[26];		  没有进行初始化，每一位都是物理地址原来存储的数字，随机
int record[26] = {0}; 将record[0]初始化为一个指定数字（为了与剩余数字统一，将其初始化为0），而剩余元素自动初始化为0！

## 所以要使用“int record[26] = {0}”和“记录index为实际index+1”的组合！

记录index为实际index+1：  
是为了避免index=0和初始值相同的顾虑！用i+1表示实际的i，避免判断和初始值相同时发生错误，最后返回时对i+1进行-1后返回i.