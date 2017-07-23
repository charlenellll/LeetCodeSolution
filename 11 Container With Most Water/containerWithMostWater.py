class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        if len(height) <= 1:
            return 0
        else:
            l = 0
            r = len(height) - 1
            maxArea = 0
            
            while l < r:
                while height[l] <= height[r] and l < r: # Pay attention to the boundary
                    if height[l] * (r - l) > maxArea:
                        maxArea = height[l] * (r - l)
                    l += 1
                while height[l] > height[r] and l < r: # Pay attention to the boundary
                    if height[r] * (r - l) > maxArea:
                        maxArea = height[r] * (r - l)
                    r -= 1
            return maxArea