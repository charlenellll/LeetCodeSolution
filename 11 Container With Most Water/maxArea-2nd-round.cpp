// 3rd round
// 16 ms, faster than 95.58%
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1, maxRes = 0;
        while( l < r ){ // rule for sliding: the shorter hand moves towards the longer hand
            int newRes = min(height[l], height[r]) * (r-l);
            maxRes = max(maxRes, newRes);
            if( height[l] <= height[r] ) l++;
            else r--;
        }
        return maxRes;
    }
};

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