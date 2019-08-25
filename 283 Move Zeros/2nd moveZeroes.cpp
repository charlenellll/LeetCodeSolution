// 16 ms, faster than 61.38% 

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0; // nums[0,k) are non-zero elements
        for(int i = 0; i < nums.size(); i++){
            if( nums[i] != 0 ){
                if( i != k ) swap(nums[i], nums[k]);
                k++;
            }
        }
    }
};