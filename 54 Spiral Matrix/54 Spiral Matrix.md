Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].

## Solution 1 - Basic: imitate spirally traverse the matrix

It requires careful design of loops to traverse the matrix.

## Solution 2 - Use 2 direction variable and 4 boundary variable. 

+ Change the variables instead of changing the loop.
+ Use the index to represent the traverse instead of traverse through the matrix itself.

This method is more concise. 

It is way faster since it replaces many for-loop with just index change(O(1)).