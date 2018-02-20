Given an integer, write a function to determine if it is a power of two.

# Solutions

## 1. Same solutions in #326 power of three

+ Recursively
+ Iteratively
+ using "log10()" so this solution is totally recursion-free and loop-free: **only applicable to power of a prime**

## 2. special trick of n&(n-1) - only applicable to power of two

Power of 2 means only one bit of n is ‘1’, so use the trick n&(n-1)==0 to judge whether that is the case.

	For example:
	8 is 1 0 0 0
	7 is   1 1 1
	8 & 7 == 0