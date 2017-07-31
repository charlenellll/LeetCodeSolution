class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        # There's no Stack interface in Python
        # Use a list to imitate operations of stack
        stack = []
        
        for i in range(len(s)):
            if s[i] == '(' or s[i] == '{' or s[i] == '[':
                stack.append( s[i] )
            else:
                if len(stack) == 0:
                    return False
                
                c = stack[len(stack) - 1]
                stack.pop()
                if s[i] == '}':
                    match = '{'
                elif s[i] == ']':
                    match = '['
                elif s[i] == ')':
                    match = '('
                    
                if c != match:
                    return False
                
        if len(stack) != 0:
            return False
        
        return True