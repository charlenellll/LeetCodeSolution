class Solution {
public:
    int maxArea(vector<int>& height) {
        assert(height.size() > 1);
        int l = 0;
        int r = height.size() - 1;
        int maxArea = 0;
        
        while(l < r){
            while(height[l] > height[r]){
                if(height[r] * (r - l) > maxArea){
                    maxArea = height[r] * (r - l);
                }
                r--;
            }
            while(height[l] <= height[r]){
                if(height[l] * (r - l) > maxArea){
                    maxArea = height[l] * (r - l);
                }
                l++;
            }
        }
        return maxArea;
    }
};