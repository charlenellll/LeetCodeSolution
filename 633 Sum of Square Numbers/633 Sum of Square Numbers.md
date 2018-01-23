Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a^2 + b^2 = c.

Example 1:

	Input: 5
	Output: True
	Explanation: 1 * 1 + 2 * 2 = 5

Example 2:

	Input: 3
	Output: False

## Solution

Problem #367 gives me intuition of using binary search. However, **binary search is useful to find one number**. To find two numbers, binary search is too trivial.

We can see that the differences between the #367 and this problem is:
+ 367 finds one number, so binary search is useful.
+ This problem is to find two numbers so collider pointers are more useful.

## Collider pointers

The requirement does not ban us from using sqrt() so we can use it.

Finding the square sum using a pair of collider pointers initialize on [0..int(sqrt(c))]