class Solution(object):        
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if len(s) == 0 or len(s) == 1:
            return True
        else:
            l = 0
            r = len(s) - 1
            
            while l < r:
                while l < r and (not s[l].isalnum()):
                    l += 1
                while r > l and (not s[r].isalnum()):
                    r -= 1
                if s[l].lower() != s[r].lower():
                    return False
                elif s[l].lower() == s[r].lower():
                    l += 1
                    r -= 1
            
            if l >= r:
                   return True

# The way of defining functions in a class is totally different from Java or C++
# And python has built-in functions to determine if characters are alphanumeric