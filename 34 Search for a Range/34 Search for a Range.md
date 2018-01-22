Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

## similar to Binary Search O(logN)

+ Use a binary search to find the location of the target
+ NOTICE! Since binary search will give you the middle-ish index of target number in the input, remember to search for its left and right to find the start and end point!

## other solition: lower_bound(), upper_bound() function

    auto iter1 = lower_bound(nums.begin(), nums.end(), target); // the location of first element >= target
    auto iter2 = upper_bound(nums.begin(), nums.end(), target); // the location of first element > target

See the sample 9ms code.