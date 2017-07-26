class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        
        record = {}
        for i in nums1 :
            if i not in record :
                record[i]  = 1;
            else:
                record[i] += 1
                
        res = []
        for x in nums2 :
            if x in record and record[x] > 0:
                res.append(x)
                record[x] -= 1
                if record[x] == 0 :
                    del record[x]
                    
        return res
        
        
            