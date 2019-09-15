[Hard]
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

Example 1:

	Input: [[1,1],[2,2],[3,3]]
	Output: 3
	Explanation:
	^
	|
	|        o
	|     o
	|  o  
	+------------->
	0  1  2  3  4

Example 2:

	Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]  
	Output: 4  
	Explanation:
	^
	|
	|  o
	|     o        o
	|        o
	|  o        o
	+------------------->
	0  1  2  3  4  5  6

NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

## Solution 1: general idea
类似447的思路（固定一个点，对它记录所有点和它的距离，相同距离假设一个距离共出现k次，在总结果中+A(k,2)因为有序）。
+ 外层循环遍历每一个点，fix为这个点
+ 内层循环从它之后的每一个点遍历并计算那个点同这个固定点的斜率，如果斜率一样，则斜率一样的点和这个固定点一同在一条线上
+ 注意特殊情况：
	+ 别的点和这个点坐标相同时：由于在同一位置，要加进所有直线里
	+ 当别的点和这个点横坐标相同时（分母为0）要特别处理：不管是在map中存key值为INT_MAX还是分为单独的veritical这一类都行
	+ 后面提到的精度溢出double精度的问题


## 精度溢出的问题

按照solution 1会有一个test case没有过：

	Input [[0,0],[94911151,94911150],[94911152,94911151]]
	Output 3
	Expected 2

是因为double的精度溢出了，0到后两个点slope都为0。

## Solution 2

In order to avoid using double type(the slope k) as map key, we can use pair (int a, int b) as the key where a=pj.x-pi.x, b=pj.y-pi.y, and k=b/a. Using greatest common divider of a and b to divide both a, b ensures that lines with same slope have the same key.

	int GCD(int a, int b) {
	        
	        if(b==0) return a;
	        else return GCD(b, a%b);
	}

When storing the pairs:

	int a=points[j].x-points[i].x, b=points[j].y-points[i].y;
	int gcd=GCD(a, b);
	a/=gcd;
	b/=gcd;
	lines[make_pair(a, b)]++;
	localmax=max(lines[make_pair(a, b)], localmax);