There is a fence with n posts, each post can be painted with one of the k colors.

You have to paint all the posts such that no more than two adjacent fence posts have the same color.

Return the total number of ways you can paint the fence.

Note:
n and k are non-negative integers.

Example:

Input: n = 3, k = 2
Output: 6
Explanation: Take c1 as color 1, c2 as color 2. All possible ways are:

	            post1  post2  post3      
	 -----      -----  -----  -----       
	   1         c1     c1     c2 
	   2         c1     c2     c1 
	   3         c1     c2     c2 
	   4         c2     c1     c1  
	   5         c2     c1     c2
	   6         c2     c2     c1

## Dynamic programming

But this problem is simple enough to not use memorizing structures.

+ same - # of way this post can be colored when its color same as the last post
+ diff - # of way this post can be colored when its color diff f the last post
+ total - total # of way this post can be colored

#### For each post:
+ its "same" =  last post's "diff"
+ its "diff" = (k-1)* last post's "total"
+ its "total" = its "same" + "diff"