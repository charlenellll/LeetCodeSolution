// 8 ms, faster than 79.89% 

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int closest = nums[n-1] + nums[n-2] + nums[n-3];
        sort( nums.begin(), nums.end() );
        for(int i = 0; i < n; i++ ){ // target1 = target - nums[i]
            int l = i + 1, r = n - 1;
            while( l < r ){
                int sum = nums[i] + nums[l] + nums[r];
                if( sum == target ) return sum;
                if( abs(sum - target) <= abs(target - closest)){
                    closest = sum; // Notice here!There is no l++, r--!!(as in 3sum or other ksum problem)此时离target的绝对值最小，并不能表明指针移动方向
                }
                if( sum > target ) r--; //另起炉灶判断指针移动方向
                else l++;
            }
        }
        return closest;
    }
};