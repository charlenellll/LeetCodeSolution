Given a binary tree, collect a tree's nodes as if you were doing this: Collect and remove all leaves, repeat until the tree is empty.

Example:
Given binary tree 

          1
         / \
        2   3
       / \     
      4   5    
Returns [4, 5, 3], [2], [1].

Explanation:
1. Removing the leaves [4, 5, 3] would result in this tree:

          1
         / 
        2          
2. Now removing the leaf [2] would result in this tree:

          1          
3. Now removing the leaf [1] would result in the empty tree:

          []         
Returns [4, 5, 3], [2], [1].

## Brutal force: worst case O(n!)

Repeatedly traverse the tree, and each time cut off all the leaves

## Postorder traversal

+ When I traverse the tree, at each level I would return a number that denotes its distance from the leaf level
+ Backtracking of DFS: when I do postorder exit I will know which level this node is on, and push back it into the result of that level

# I made many mistakes of C++ in this problem for the first time!

I have never encountered the errors occur in this problem before!  
It is worthy of going through several times.  
I need to read C++ primer and get to know all the basics of C++.