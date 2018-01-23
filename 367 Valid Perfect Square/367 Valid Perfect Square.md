Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

	Input: 16
	Returns: True

Example 2:

	Input: 14
	Returns: False

## Normal solution O(n)

Try i from 1 to **num/2+1** to find if i\*i == num.

// Notice that we have to use num/2+1 to make sure it is bigger than sqrt(num).

## Binary Search O(logN)

find if mid\*mid == num