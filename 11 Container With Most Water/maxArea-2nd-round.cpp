// 20 ms, faster than 57.44% of C++ online submissions 
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxVol = 0, l = 0, r = height.size()-1;
        while( l < r ){
            if( height[l] <= height[r] ){
                maxVol = max(maxVol, height[l]*(r-l));
                l++;
            }
            else{ // height[l] > height[r]
                maxVol = max(maxVol, height[r]*(r-l));
                r--;
            }        
        }
        return maxVol;
    }
};