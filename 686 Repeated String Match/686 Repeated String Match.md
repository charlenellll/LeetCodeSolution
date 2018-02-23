Given two strings A and B, find the minimum number of times A has to be repeated such that B is a substring of it. If no such solution, return -1.

For example, with A = "abcd" and B = "cdabcdab".

Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring of it; and B is not a substring of A repeated two times ("abcdabcd").

Note:
The length of A and B will be between 1 and 10000.

## C++ string find() function

It's time complexity is O(m\*n).

### In this problem, the size of A:

+ when A's size < B's size, we should repeat A
+ when A's size >= B:
	+ we use repeatedString.find() to find out whether B is in it
	+ If not, we can allow **one more time of A to be repeated**, to allow all characters in A be sliding through by a window of size of B

In conclusion:

A's size just need to cover B (>= B), we will find B in it; if B is not found, we should + 1 more A to allow all characters in A can be sliding through by a window of size of B
Generally, size of repeatedA should be exactly >= B or + 1 A. No more. If greater than this length, there is no solution.