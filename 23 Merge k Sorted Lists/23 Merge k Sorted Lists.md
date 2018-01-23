Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

# Solution

**Hard!**

It is an advanced version of problem #21 by changing the number of sorted list by 2 to k.

## Basic solution : ransformation of #21: Merge Sort + Merge two sorted lists O(nklogk)

// k is the number of sorted lists, and n is the length of each list

See my solution. Its runtime is 29ms and it beats 53.48% cpp submissions. Fast enough.

# Advanced solutions

## priority_queue or Min Heap O(nklogk)

**I need to try it when I have time**

## Divide and Conquer: Tournament Tree (Winner Tree) O(klogN)

like Merge Sort.