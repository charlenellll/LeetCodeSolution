Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:

	[
	 [ 1, 2, 3 ],
	 [ 8, 9, 4 ],
	 [ 7, 6, 5 ]
	]

# Solution

It is basically the same as 54 Spiral Matrix.  
So both solutions in 54 work in this problem.

For solution 1:  
+ set an int number as the current number, starts from 1.
+ just change all occurences of res.push_back(matrix[][]) to matrix[][] = number++;

For solution 2, it is even more convenient:
+ just change i to start from 1 and end when i == n\*n (since we want the number starts from 1, and i basically already serves this purpose!)
+ change res.push_back( matrix[x]\[y]) to matrix[x\][y] = i;

Since solution 2 is way faster, my code only used solution 2.