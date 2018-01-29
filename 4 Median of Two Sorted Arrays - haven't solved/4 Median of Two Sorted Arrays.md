There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:

	nums1 = [1, 3]
	nums2 = [2]

	The median is 2.0
Example 2:

	nums1 = [1, 2]
	nums2 = [3, 4]

	The median is (2 + 3)/2 = 2.5

# Solution - a very classic Divide and Conquer problem

## Two pointers O(m+n)-NAHHH

Use two pointers to start from two array's head, compare them and put the smaller one to a new array, until find the median.

Not satisfy the time complexity requirement of this problem.

## Divide and Conquer O(log(m+n)) √

The useful reference links: 

https://hk029.gitbooks.io/leetbook/%E5%88%86%E6%B2%BB/004.%20Median%20of%20Two%20Sorted%20Arrays[H]/004.%20Median%20of%20Two%20Sorted%20Arrays[H].html?q=

https://segmentfault.com/a/1190000007938108

### Find the k-th (median) element of two sorted array

http://blog.csdn.net/yutianzuijin/article/details/11499917/

We want to find the k-th smallest element in two sorted array: (specially, for the median, k = (m+n)/2 )  

Suppose two arrays A and B both have more than k/2 elements, we compare A[k/2-1] and B[k/2-1]:  
They are respectively the k/2-th smallest element in A and B.  
+ For convenience, we always use the smaller array as A and longer one as B
	+ partition of A: pa = min(k/2, m)
	+ partition of B: pb = k - pa

Compare A[k/2-1\] (A[pa-1]) and B[k/2-1\] (B[pb-1]):  
+ if < , then elements in A[0..k/2-1] are all in the subset of smallest k elements of two arrays. In other words, A[k/2-1] is not likely to be larger than the k-th smallest element
	+ find the (k-pa)-th element in A[pa..m] and B[0..n]
+ if > , then elements in B[0..k/2-1] are all in the subset of smallest k elements of two arrays. In other words, B[k/2-1] is not likely to be larger than the k-th smallest element
	+ find the (k-pb)-th element in A[0..m] and B[pb..n]
+ if = , it is the k-th smallest element we are looking for. return it. (When finding the median, we have also consider about whether m+n is odd number or even number)

Finding the median, if m+n is:
+ odd: k = (m+n)/2+1, return k-th element
+ even: k = (m+n)/2+1, return value = average of k-th  and (k-1)-th elements

Some other base conditions:
+ if A or B is empty, return B[k-1] or A[k-1]
+ if k == 1, return min(A[0], B[0])
+ if A[k/2-1] == B[k/2-1], return either one is okay.
