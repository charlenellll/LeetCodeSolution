class Solution(object):
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        # Define the list of frequencies in s and p
        freqS = [0] * 26
        freqP = [0] * 26
        index = []
        
        for x in range(len(p)):
            freqP[ord(p[x])%97] += 1
        
        l = 0
        r = -1
        while l < len(s):
            if r-l+1 <= len(p) and r+1 < len(s):
                r += 1
                freqS[ord(s[r])%97] += 1 # Note that in python it cannot directly recognize char as its ASCII number, need ord()
            else:
                freqS[ord(s[l])%97] -= 1
                l += 1
            if freqS == freqP:
                index.append(l)
        return index
                