class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        record = {}
        # Note that we have to get the index of each element, so the iteration is slightly different
        for i,element in enumerate(nums):
            complement = target - element
            if complement in record:
                res = [i, record[complement]]
                return res
            record[element] = i