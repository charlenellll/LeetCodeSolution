class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        record = {}
        
        for i in nums:
            if i not in record:
                record[i] = 1
            else:
                record[i] += 1
        
        # Pay attention to the way of iteration, enumerate() is not suitable
        for j in record.keys():
            if record[j] >= 2:
                return True
            
        return False