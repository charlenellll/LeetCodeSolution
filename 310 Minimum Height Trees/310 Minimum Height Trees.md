For a undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.

Format
The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels).

You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

Example 1:

Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]

        0
        |
        1
       / \
      2   3
return [1]

Example 2:

Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

     0  1  2
      \ | /
        3
        |
        4
        |
        5

return [3, 4]

Note:

(1) According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”

(2) The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

# Special solution

This problem is really special and it has its own special solution.

## not normal BFS + bite off the leaves each time

when n == 1 or n == 2 it satisfy the requirement, we can just return it. 
when n > 2, there are two types of nodes: leaf node and non-leaf node.
+ when we choose the leaf node as the root, the height of the tree will always be (1 + the height of tree rooted by its neighboring non-leaf node), we can see it from examples
+ so we always discard the leaves until there are only 1 or 2 nodes left, and that's the result, return it

# Variantion of this problem - Facebook

The interview question I got from facebook was a variation of this problem. That problem is basically the same as this problem, except that it didn't give us the number of nodes n.  
So a crucial point the interviewer paid attention to is: how to find the possible root? Why would you choose it as a start point to check if it is the root we want? How do you choose the next one possible root?

**I shall consider this when I got time!**