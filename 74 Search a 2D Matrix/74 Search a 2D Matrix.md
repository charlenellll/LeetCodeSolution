Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

	Example 1:
	
	Input:
	matrix = [
	  [1,   3,  5,  7],
	  [10, 11, 16, 20],
	  [23, 30, 34, 50]
	]
	target = 3
	Output: true
	
	Example 2:
	
	Input:
	matrix = [
	  [1,   3,  5,  7],
	  [10, 11, 16, 20],
	  [23, 30, 34, 50]
	]
	target = 13
	Output: false


## Solution 1: 从左上角或右下角开始扫，直观解法 O(M+N)

对比240只能从右上角或左下角开始扫（因为不能保证下面的行比上面的行的数字大，因此要约束在行最大或列最大之位开始，才能每次只移动一个index）

## Solution 2: 二分查找法 O(logM+logN) 

+ **使用二分查找的话，行和列的二分查找要分开写！**
  + 先二分查找找到行，while(rowMin < rowMax)使得最终rowMin == rowMax
  + 再二分查找列，while(colMin <= colMax)使得最终colMin > colMax才能完全排除所有情况！！
+ 再三注意行与列的终止条件不同！