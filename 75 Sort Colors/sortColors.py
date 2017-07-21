class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        zero = -1
        two = len(nums)
        
        i = 0
        while (i < two): # Is it entirely impossible to use for-loop in python in this situtation?
            if nums[i] == 1:
                i += 1
            elif nums[i] == 2:
                two -= 1
                nums[two],nums[i] = nums[i],nums[two]
            else:
                zero += 1
                nums[zero],nums[i] = nums[i],nums[zero]
                i += 1
        