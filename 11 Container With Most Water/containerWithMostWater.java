public class Solution {
    public int maxArea(int[] height) {
        if(height.length <= 1)
            return 0;
        else{
            int l = 0;
            int r = height.length - 1;
            int maxArea = 0;
            
            while(l < r){
                while(height[l] < height[r]){
                    if(height[l] * (r - l) > maxArea){
                        maxArea = height[l] * (r - l);
                    }
                    l++;
                }
                // Note that boundaries are always different in Java than C++
                // There are more chances of compilation error so the statement is slightly different
                while(height[r] <= height[l] && l < r){ 
                    if(height[r] * (r - l) > maxArea){
                        maxArea = height[r] * (r - l);
                    }
                    r--;                    
                }
            }
            return maxArea;
        }
    }
}