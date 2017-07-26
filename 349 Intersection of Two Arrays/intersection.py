class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        
        record = set( nums1 )
        compare = set ( nums2 )
        resultSet = record & compare
        res = list(resultSet)
        return res
        