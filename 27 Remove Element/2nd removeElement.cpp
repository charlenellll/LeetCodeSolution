// 0 ms, faster than 100.00%

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0; // nums[0,k) are numbers != val, k is the length
        for(int i = 0; i < nums.size(); i++){
            if( nums[i] != val ){
                if( i != k ) swap(nums[i], nums[k]);
                k++;
            }
        }
        return k;
    }
};