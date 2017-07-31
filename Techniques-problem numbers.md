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

20





## Need to be done:

125: in Java

3: Python

88: Java, Python

447: Java, Python

220: Java, Python

15,18,16,49,215-medium  76,149-hard
