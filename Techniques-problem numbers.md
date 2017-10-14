## Problems about Array

To begin with, a simple question: 283

+ To minimize space complexity to O(1), use an extra index k as pointer.
	+ Exercise: 27,26,80

Some classic problems:

+ Quick sort with 3-way partition:75

Exercise: 88(Merge), (215)

+ Two pointers:
	+ Collider pointer: 167,125,344,345,11
	+ Sliding window: 209,3,438,(76-hard）

## Problems about Hash Table

+ Set: 349
+ Map: 350

Exercise: 242, 202, (290(pattern), 205,(同构) 451)

A classic problem : 1

4-4 (Exercise: 15, 18, 16(We may not need Hash Table in this problem))-All are medium!

All hash table problems requires our determination on what to search for:

+ Select the key flexibly: 454, 447(a little technically complicated for beginners in C++ or any other language)

4-5 (Exercise: 49-medium; 4-6: 149-hard)

+ Hash table + sliding window: 219

Compare the similarity and differences between 3# and 219#:

Similarity: 

	+ They are both problems about hash table + sliding window.

Differences:

	+ The number of values is limited in 3#, only 256 types, so we used an array instead of set or map.
	+ The size of sliding window is flexible in 3# while it is fixed in 219#.

Exercise: 217 (Simpler than )

220(More difficult than 219)

## Problems about Linked list

A simple question: 206

Exercise: 92, 83, 2-median, (86, 328, 445-median)

+ Virtual head node (dummyHead): 203

Exercise: 82, 21

+ Complicated pointer operations: it won't be horrify if we think through the process clearly. 24

(Exercise: 25-hard, 147-Insersion Sort in Linked list, 148-Use (Merge Sort from bottom up) to sort a linked list in O(nlogn) time-Medium)

+ Sometimes there's something more than just pointer operations: 237 (delete the node by changing its value instead of usual method when we have no access to the node before it)

+ Two pointers: 19

Exercise: 61, （143, 234)


## Stack and Queue

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

## Binary Tree and Recursion

+ Binary tree: A binary tree has a natural recursive structure. It generally consists of two parts: 
	+ Base case
	+ Recursive steps 

104; (111: There's a trap upon the base case, should be careful)

226; (Exercise: 100，101，222，110) 

+ Be careful about the terminal condition (base case) of a recursion
	+ 112
	+ (Exercise: 111,404

+ Use the return value of a recursive function cleverly:
	+ 257



## Need to be done:

125: in Java

3: Python

15,18,16,49,215-medium  76,149-hard

Amazon: 675

### need to finish in Java and Python

88

447

220

144, 94, 145; 102, 279



347

104
