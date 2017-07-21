class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        k = 0;
        
        if len(nums) == 0: # If the array is empty
            return 0;
        else: # If it is not empty
            for i in range(1,len(nums)):
                if nums[i] > nums[i-1]:
                    if i != k:
                        k += 1
                        nums[k] = nums[i]
                    else:
                        k += 1
            return k+1