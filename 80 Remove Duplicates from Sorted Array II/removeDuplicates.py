class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        k = 0
        count = 1
        
        if len(nums) == 0:
            return 0
        else:
            for i in range(1,len(nums)):
                if nums[i] > nums[i-1]:
                    count = 1
                    k += 1
                    if i != k:
                        nums[k] = nums[i]
                elif nums[i] == nums[i-1] and count == 1:
                    count =2
                    k += 1
                    if i!= k:
                        nums[k] = nums[i]
            return k+1