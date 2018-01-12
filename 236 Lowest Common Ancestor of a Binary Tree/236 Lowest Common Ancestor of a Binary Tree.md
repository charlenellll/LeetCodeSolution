Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4

For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

## Solution 1 - based on 235

Unlike 235, this is binary tree instead of binary search tree.

We can use the logic of 235:

+ If the recursive function find p and q both in left or right subtree, the lowest common ancestor must be in that tree;
+ If one of them in the left subtree and another one is in another subtree/ p is the root itself / q is the root itself, the root is the answer


// First version:

// I used a recursive function to decide if p or q is in either subtree, it was a waste of time since I can build a function find the root of the subtree it is in.

// Second version:

// the recursive function finds the answer directly

Always remember to optimize the function!

