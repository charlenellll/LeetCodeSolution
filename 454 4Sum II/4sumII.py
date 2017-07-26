class Solution(object):
    def fourSumCount(self, A, B, C, D):
        """
        :type A: List[int]
        :type B: List[int]
        :type C: List[int]
        :type D: List[int]
        :rtype: int
        """
        record = {}
        for x in C:
            for y in D:
                if x+y not in record:
                    record[x+y] = 1
                else:
                    record[x+y] += 1
        
        res = 0
        for x in A:
            for y in B:
                if 0-x-y in record:
                    res += record[0-x-y]
                    
        return res