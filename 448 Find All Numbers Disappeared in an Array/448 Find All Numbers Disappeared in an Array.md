Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

	Input:
	[4,3,2,7,8,2,3,1]

	Output:
	[5,6]

# Solutions

## 1. Brutal-force O(NlogN) time and O(1) space

see my code. it is pretty slow.

# 2. O(n) Time and O(1) space

A blog about three ways of delicate designs. https://www.cnblogs.com/grandyang/p/6222149.html

I'll just choose one:

## Use the position to decode if a number appeared or not

Really delicate design! worth understanding

The idea is very similar to problem 442. Find All Duplicates in an Array: https://leetcode.com/problems/find-all-duplicates-in-an-array/.

+ First iteration to negate values at position whose equal to values appear in array. 
+ Second iteration to collect all position whose value is positive, which are the missing values. 

Complexity is O(n) Time and O(1) space.

	class Solution {
	public:
	    vector<int> findDisappearedNumbers(vector<int>& nums) {
	        int len = nums.size();
	        for(int i=0; i<len; i++) {
	            int m = abs(nums[i])-1; // index start from 0
	            nums[m] = nums[m]>0 ? -nums[m] : nums[m];
	        }
	        vector<int> res;
	        for(int i = 0; i<len; i++) {
	            if(nums[i] > 0) res.push_back(i+1);
	        }
	        return res;
	    }
	};
