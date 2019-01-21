class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if( nums.size() < 3 ) return res;
        sort(nums.begin(), nums.end());
        for(int index = 0; index < nums.size(); index++){
            // find two other elements add up to 0 with this target
            while( index >0 && nums[index] == nums[index-1]) index++; // rule out the same target
            int l = index+1, r = nums.size()-1;
            while( l < r ){
                int sum = nums[index] + nums[l] + nums[r];
                if( sum == 0 ){
                    int result[3] = {nums[index], nums[l], nums[r]};
                    res.push_back(vector<int>(result, result+3));
                    l++, r--;
                    // when adding to this target, rule out all the same numbers
                    while( nums[l] == nums[l-1] ) l++;
                    while( nums[r] == nums[r+1] ) r--;
                }
                else if( sum > 0 ) r--;
                else l++;
            }
        }
        return res;
    }
};