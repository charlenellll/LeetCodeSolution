Given two sparse matrices A and B, return the result of AB.

You may assume that A's column number is equal to B's row number.

Example:

	A = [
	  [ 1, 0, 0],
	  [-1, 0, 3]
	]

	B = [
	  [ 7, 0, 0 ],
	  [ 0, 0, 0 ],
	  [ 0, 0, 1 ]
	]


	     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
	AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
	                  | 0 0 1 |

## Solution : Brutal-force

Brutal-force matrix multiplication.

## The only tricky part is the time complexity
Attention: simple matrix multiplication will reach the time limit!!
+ This is **Sparse Matrix** so there are lots of 0s!!
+ Do remember to test if any element is 0 in the matrix, then no need for multiplication!