Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

## Just like 3sum but tricky when you find the current closest sum

+ 1. Do not move the pointers (l++, r--) when current sum is the closest
	+ Leave it to following judgement. Whether or not it is the closest sum, the moving direction of pointer should be judged otherwise.
	+ 因为此时离target的绝对值最小，并不能表明指针移动方向，最后移动方向还是要按两者只差的大小来判断左右
+ 2. Notice that the (l++, r--;) operation in 3sum solution is to avoid duplicate solutions in the result. In fact we should not move l pointer and r pointer together but in that situation this is right. So be careful before use this kind of operation.