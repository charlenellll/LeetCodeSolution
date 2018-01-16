Given a nested list of integers, return the sum of all integers in the list weighted by their depth.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Different from the previous question where weight is increasing from root to leaf, now the weight is defined from bottom up. i.e., the leaf level integers have weight 1, and the root level integers have the largest weight.

Example 1:
Given the list [[1,1],2,[1,1]], return 8. (four 1's at depth 1, one 2 at depth 2)

Example 2:
Given the list [1,[4,[6]]], return 17. (one 1 at depth 3, one 4 at depth 2, and one 6 at depth 1; 1\*3 + 4\*2 + 6\*1 = 17)

## Different from 339

The difference is that we cannot compute the sum until we know the depth of each level.

### 1.Recursive: Traverse once to know the maximum depth + Same method as 339 with height-- for each level

Most naive way:  
+ Traverse once (recursive) to get the max depth
+ Traverse again (recursive) and add up the numbers

A smarter way:  
+ Traverse the list once(recursive) and record each element with its depth (in a vector)
+ Traverse the vector once (iterative) to add up the sum

### 2. Recursive: New method: pass the sum of each level to the next level and add it up again

Worth trying.

### 3. Iterative

Use a queue. see the 0ms sample code.