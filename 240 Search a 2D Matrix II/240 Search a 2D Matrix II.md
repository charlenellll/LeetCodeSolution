Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
Example:

Consider the following matrix:

	[
	  [1,   4,  7, 11, 15],
	  [2,   5,  8, 12, 19],
	  [3,   6,  9, 16, 22],
	  [10, 13, 14, 17, 24],
	  [18, 21, 23, 26, 30]
	]

Given target = 5, return true.

Given target = 20, return false.

## Trick：从右上角或左下角开始扫 O(m+n)

总体思路和74相似。不同之处在于下面一行的数不一定比上面一行的大，所以需要手段使我们的规则每次只移动一个index（坐标/指针）。

+ 因为不能保证下面的行比上面的行的数字大，因此要约束在行最大或列最大之位开始，才能每次只移动一个index