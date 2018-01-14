Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

## Binary search tree has order + Stack: meets both requirement !!

Because the time complexity and space complexity requirment: 
+ use a stack to store the tree pointer
+ always push the left child of the current node into the stack when constructing the initial stack or maintain it. (After pop out the smallest node, push its right child into the stack and maintain the stack by pushing the left child sequence of it into the stack)

## Binary search tree + Queue: simpler but space complexity is O(V)

