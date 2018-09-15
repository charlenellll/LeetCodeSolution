// 72 ms
// beats 88.1%

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if( nums.size() < 3) return res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if( i > 0 && nums[i] == nums[i-1]) continue;
            int p = i+1, q = nums.size()-1;
            while( p < q ){
                int sum = nums[i]+nums[p]+nums[q];
                if( sum == 0 ){
                    res.push_back(vector<int>{nums[i], nums[p], nums[q]});
                    while( p < q && nums[p] == nums[p+1] ) p++;
                    while( p < q && nums[q] == nums[q-1]) q--;
                    p++, q--;
                }
                else if( sum > 0 ) q--;
                else p++;
            }
        }
        return res;
    }
};