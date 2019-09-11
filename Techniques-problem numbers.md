Most problem set in interviews are testing your basic knowledge.

DO NOT underestimate the importance of basics.

# Problems about Array

To begin with, a simple question: 283

+ To minimize space complexity to O(1), use an extra index k as pointer.
  + Exercise: 27,26,80

Some classic problems:

+ **Quick sort with 3-way partition:75**

Exercise: 88(Merge as in Merge Sort),  215

+ Two pointers:
  + Collider pointer: 167,125,344,345,11 
  + Sliding window: 209,3,438,(76-hard）

#### 对比：

+ **对撞指针**：
  + 使用前提：数组，有序。
  + 终止条件：while(l < r)
+ **滑动窗口**：
  + 适用场景：数组无序，所求结果与数组连续相邻数据有关
  + 终止条件 while(l < num.size())

# Problems about Hash Table

+ Set: 349
+ Map: 350

Exercise: 242, 202, (290(pattern), 205,(同构) 451)

#### For 1-to-1 relationship problems:  map letter/words to the index

Code can be more concise if map letter/words to the last index they show up (instead of each other)

#### About Map order: 默认按键值升序，使用less\<T>

```
    1、map指定less作为其默认比较函数(对象),就是默认按键值升序排列
    // map<string, int> name_score_map;

    2、可以自定义，按照键值降序排列，注意加载 
    // #include <functional> // std::greater
    // map<string, int, greater<string>> name_score_map;
```

A classic problem : 1

4-4 (Exercise: 15, 18, 16(We may not need Hash Table in this problem))-All are medium!

All hash table problems requires our determination on what to search for:

+ Select the key flexibly: 454, 447(a little technically complicated for beginners in C++ or any other language)

4-5 (Exercise: 49-medium; 4-6: 149-hard)

+ Hash table + sliding window: 219

Compare the similarity and differences between 3# and 219#:

+ Similarity: 
  + They are both problems about hash table + sliding window.

+ Differences:
  + The number of values is limited in 3#, only 256 types, so we used an array instead of set or map.
  + The size of sliding window is flexible in 3# while it is fixed in 219#.

Exercise: 217 (Simpler than )

220(More difficult than 219)

## unordered_set和unordered_map内部实现与set和map大有不同：

+ set和map内部实现是基于Red Black-Tree(红黑树)
  + 查找，插入，删除一个元素：O(logN)
  + 根据一组输入，建立一颗含有N个元素的树：O(NlogN)
+ unordered_set和unordered_map内部实现是基于哈希表(hashtable)
  + 查找，插入，删除：linear time = O(1)
  + 同样的一组输入，建立含N个元素的hash table: O(N)，比红黑树快！

# Problems about Linked list

A simple question: 206

Exercise: 92, 83, 2-median, (86, 328, 445-median)

+ Virtual head node (dummyHead): 203

Exercise: 82, 21

+ Complicated pointer operations: it won't be horrify if we think through the process clearly. 24

(Exercise: 25-hard, 147-Insersion Sort in Linked list, 148-Use (Merge Sort from bottom up) to sort a linked list in O(nlogn) time-Medium)

+ Sometimes there's something more than just pointer operations: 237 (delete the node by changing its value instead of usual method when we have no access to the node before it)

+ Two pointers: 19

Exercise: 61, （143, 234)

A technique is often used in singly linked list:

## |Fast pointer and slow pointer 快慢指针| 

### 1. Find the midpoint of the linked list 寻找链表中点/在有序链表寻找中位数

#### 234 Palindrome Linked List:

For the follow up requirement of O(N) Time and O(1) Space, we should use:
+ find the midpoint of a singly linked list: use a fast pointer and a slow pointer;
+ reverse the second half of the singly linked list: see 206 Reverse Linked List.

### 2. Check if the singly linked list has a cycle in it 检查链表是否有环

为什么用快慢指针找链表的环，快指针和慢指针一定会相遇？

可以用数学归纳法来思考。首先，由于链表是个环，所以相遇的过程可以看作是快指针从后边追赶慢指针的过程。那么做如下思考：  
1：快指针与慢指针之间差一步。此时继续往后走，慢指针前进一步，快指针前进两步，两者相遇。
2：快指针与慢指针之间差两步。此时唏嘘往后走，慢指针前进一步，快指针前进两步，两者之间相差一步，转化为第一种情况。
3：快指针与慢指针之间差N步。此时继续往后走，慢指针前进一步，快指针前进两步，两者之间相差(N+1-2)-> N-1步。

因此，此题得证。所以==快指针必然与慢指针相遇。又因为快指针速度是慢指针的两倍，所以相遇时必然只绕了一圈(当快指针速度是慢指针的两倍时)==。如果速度比不同，最终都会相遇，只是圈数不同。

或者更直观的理解：当快指针的速度是慢指针的两倍时，相对于慢指针每次前进一格，如果有环，必定能一格一格靠近慢指针直到追击成功。

#### 141 Linked List Cycle

# Stack and Queue

+ Stack:

  + Classic stack problem - to find the nearest element need to match in a nested hierarchical relationship: 20

  (Exercise: 150, 71

  + Recursion: recursive algorithms in binary tree: three-ways of traversal: 144, 94 , 145 (Use a stack to imitate the system stack in order to do it iteratively instead of recursively)

  (Exercise: 341

+ Queue:

  + BFS: Breadth-first search in binary tree: 102

  (Exercise: 107, 103, 199

  + Find the shortest path in a graph: Mostly these question don't seem related to graphs. 279
    ( Exercise: 127, 126

  + Priority queue: 347
    (Exercise: 23)

# Binary Tree and Recursion

+ Binary tree: A binary tree has a natural recursive structure. It generally consists of two parts: 
  + Base case
  + Recursive steps 

104;  111: There's a trap upon the base recursive step, should be careful

226; (Exercise: 100，101，222，110) 

+ Be careful about the terminal condition (base case) of a recursion
  + 112
  + (Exercise: 111,404

+ Use the return value of a recursive function cleverly:
  + 257
  + (Exercise: 113,129)

+ More complicated recursion logic
  + 437

+ Binary Search Tree
  + 235
  + (Exercise: 98, 450, 108, 230， 236(LCA problem))
  + 当我使用inorder traversal遍历一棵二分搜索树，能得到一个从小到大的有序数组

# Recursion and Backtracking

This technique can be used in tree-shaped problems.
+ Tree-shaped problems
  + 17

+ Backtracking: this term is always used when I need to return a value
  + Time complexity: for Leetcode #17: 3^n = O(2^n)
  + It is the primary method to achieve brute-force solutions(when n is unknown)
    (Exercise: 93, 131)

+ Application of backtracking:
  + Permutations
    + 46: the numbers are distinct
    + (Exercise: 47: the numbers are not distinct)
  + Combinations
    + 77
    + Pruning of Backtracking:
      + 77 - optimization
    + （Exercise: 39, 40, 216, 78, 90, 401)

+ Backtracking on 2-D plane: 2 classic problems:
  + 79 // Word Search
  + **Floodfill** algorithm: 
    + 200 // Number of islands
    + (Exercise: 130, 417)

+ Backtracking is the basis of traditional artificial intelligence
  + 51: N-Queens
  + (Exercise: 52: N-Queens II - it can be faster by many optimization)
  + A cool exercise: (37: Sudoku Solver)

# Dynamic Programming

> One problem about the course is it lacks concepts about recursive equation. So it is more fancy in techniques but did no help for me, for example, 9-7 is really hard to understand without a proper recursive equation, which is exactly it lacks.

Recursion problem - overlapping subproblems:
+ Memoizing search - recursive: top-down
+ Dynamic programming - non-recursive: bottom-up

The technique to solve dynamic programming problems:
+ 1. find out naive recursive procedures
+ 2. use memoizing: top-down approach, to figure out the structure
+ 3. optimize it using dynamic programming: botom-up approach

70  
(Exercise: 120, 64)

+ Find out subproblems:
  + 343
  + (Exercise: 279, 91, 62, 63)

+ Be aware of the specific definition of the state and its Recursive Equation:
  + 198
  + (213 - put 198 in a ring; 337- put 138 in a binary tree; 309)

> Knapsack problem:  
> The capacity of the knapsack is C. There are n items named 0..n-1, for each item, its weight is w(i) and value is v(i). This problem is to solve that how to fill the knapsack that the sum of weights is no larger than the capacity and the sum of values is greatest.

+ Knapsack:
  + Bottom up: 2D-Dynamic Programming
  + Lots of varieties of knapsack problems
  + 416： **It's kind of hard to understand. I can't solve it well.**
  + (Exercise: 322, 377 - 面试时：元素能否重复取？ 取元素的顺序是否相关，474，139， 494)
    ** 9-7 is really hard for me. I shoud revisit this**

+ Longest increasing subsequence:
  + 300 (it has a O(NlogN) optimization: MergeSort)
  + (Exercise: 376)

+ Longest(greatest) common subsequence (GCS):
  + A useful method to process strings such as genetic engineering
  + Let LCS(m,n) be the length of the LCS of S1[0..m] and S2[0..n]
  + LCS(m,n) = 0 if (m == 0 or n == 0)
  + LCS(m,n) = 1 + LCS(m-1,n-1), if S1[m] == S2[n]
  + LCS(m,n) = max{LCS(m-1, n), LCS(m, n-1)}, if S1[m] != S2[n]

+ Dijkstra single source shortest path

+ Rebuild the answer from the path: Using Dynamic Programming to give specific answer.

+ There are more dynamic programming problems in Leetcode but tend to be difficult.


# Greedy algorithm

The difficult part about greedy algorithm is **to decide if this problem can be solved by greedy algorithm.**

It always concerns about sorting coz always related to max or min value.

+ Assign cookies
  + 455
  + (Exercise: 392: you won't even notice that you are using greedy algorithm)

+ Greedy Algorithm and Dynamic Programming
  + 435: Non-overlapping intervals.
    + Sorting the intervals: always use the start index of it.
    + Dynamic programming: like a longesgt increasing subsequence problem.

NOT all dynamic programming problem can be solved with greedy method!

+ Greedy choice property:
  + It's hard to prove it
  + Use counterexample!
    + Suppose we use greedy method, can the small example problem solved by it?
    + If not, then we can't use greedy method.
  + How can we prove correctness of greedy-choice property if we can't find any couterexample?
    + Mathematical induction
    + Proof by contradiction (Reductio ad absurdum):
      + Let greedy method be A
      + Let the (imaginary) optimal solution be O
      + Prove that A can replace O without any influence on the optimal result
      + So A is optimal
      + This problem can be solved by greedy method

+ Problems using greedy method (but not just greedy method!):
  + Minimum spanning tree
  + Shortest path

+ Important part about this category: try top solve more problems and get a hold of what kind of problems can be solved by greedy algorithm, what cannot be.

------------------

## Some thoughts I get when I deal with Leetcode

170 Two Sum III:  

My understanding of collider pointer upgrade a level:  
I only need to use collider pointers on the data structures that I cannot know all elements' values such as a sorted array. On data sructure such as map and set I can know all the keys so there is no need for two pointers.

In this problem I used unordered_map so I don't need to use collider pointers, I can just traverse the map once and find if each key's completement exists in this map (&& key\*2 != target value) or key\*2 == target value.

 

##### ASCII code has 256 members, so int array needs 256 elements.

