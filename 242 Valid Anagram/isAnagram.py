class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s) != len(t):
            return False
        
        record = {}
        
        for x in s:
            if x not in record:
                record[x] = 1
            else:
                record[x] += 1
                
        for y in t:
            if y not in record:
                return False
            elif y in record and record[y] > 0 :
                record[y] -= 1
                if record[y] == 0:
                    del record[y]
                    
        return True
            