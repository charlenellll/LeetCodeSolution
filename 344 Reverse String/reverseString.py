class Solution(object):
    def reverseString(self, s):
        """
        :type s: str
        :rtype: str
        """
        if len(s) == 0 or len(s) == 1:
            return s
        else:
            l = 0
            r = len(s) - 1

            # Note that in Python, string is unchangable so we need to convert it to a list
            stemp = list(s)
            while l < r:
                stemp[l],stemp[r] = stemp[r],stemp[l]
                l += 1
                r -= 1
            return "".join(stemp)