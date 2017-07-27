class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        if n == 1:
            return True;
        
        sumResult = set();
        current = n
        while current > 0:
            
            temp_sum = 0
            while current > 0:
                temp_sum += (current % 10) * (current % 10)
                current /= 10
            
            if temp_sum == 1:
                return True
            current = temp_sum
            
            if temp_sum in sumResult:
                return False
            else:
                sumResult.add(temp_sum)
            
        return False