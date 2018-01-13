You need to find the largest value in each row of a binary tree.

Example:
Input: 

          1
         / \
        3   2
       / \   \  
      5   3   9 

Output: [1, 3, 9]

## BFS

Because I'm getting some information in each row of the tree, I should use level order traversal.

### The optimization:
+ In old version I use pair of (node,level) to notify the while-loop the level information of each node
+ Optimization: instead of make_pair(node,level), use a for-loop in the while(!q.empty()){} loop
