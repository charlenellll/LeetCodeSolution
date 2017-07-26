class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        record = set()
        for i,element in enumerate(nums):
            
            if element in record:
                return True
            record.add(element)
            if len(record) == k+1:
                record.remove(nums[i-k])
        
        return False