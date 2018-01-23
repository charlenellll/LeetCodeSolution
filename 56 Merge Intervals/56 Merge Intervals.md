Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

## My first thought: Merge Sort (Wrong idea!) O(NlogN)

It is really trivial! And hard to deal with the index.

My original thought was:  
+ Sort the intervals in increasing order
+ Using mergeSort

Wrong! Because merging of intervals will change the size of the input and it is pretty hard to deal with the indexes.

## Sort the intervals O(NlogN) + scan through once and merge it at the same time O(N)

This method is easy to think but need delicate implementation to avoid all errors.
+ sort the intervals using my own "compare" method
+ The most safe way to implement this solution: merging the intervals by compare the interval in the input vector and ==**the last element in the result vector**==.

// for my first few solutions, I operate on the original input vector: there are some bad access generating error for the input [[1,4],[1,4]] and I don't know why.

## Map

+ Sort the intervals O(NlogN)
+ Use a map to record each intervals O(N)

A blogger on the Internet said that we need to use multimap instead of map
	+ Different from map, multimap can record duplicate elements

# My confusion

## Interval tree (2-3 tree with major key a and minor key b for each interval (a,b))

Use an interval tree can make sure each interval to be inserted, located and deleted in O(logN) time.
But by using the vector, it seems I can insert, delete in O(1) time, am I wrong? Why interval tree is more costly?