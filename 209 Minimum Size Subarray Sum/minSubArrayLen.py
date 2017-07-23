class Solution(object):
    def minSubArrayLen(self, s, nums):
        """
        :type s: int
        :type nums: List[int]
        :rtype: int
        """
        l = 0
        r = -1
        temp_sum = 0
        res = len(nums) + 1
        
        while l < len(nums):
            if r+1 < len(nums) and temp_sum < s:
                r += 1
                temp_sum += nums[r]
            else:
                temp_sum -= nums[l]
                l += 1
            if temp_sum >= s:
                res = min( res, r-l+1)
        if res == len(nums) + 1:
            return 0
        return res