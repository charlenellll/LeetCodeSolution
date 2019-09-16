You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7


## Solution 1: reverse singly linked list + add up numbers in 2 linked list

The combination of Leetcode 2# and 206#.

## Solution 2: Stack

In the follow up question, we are not supposed to modify the input lists.

Then use stacks can solve this problem.