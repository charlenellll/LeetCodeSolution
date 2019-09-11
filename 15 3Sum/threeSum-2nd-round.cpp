// The old solution below has a failed test case: [0,0,0], heap-buffer-overflow
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>> res;
//         if( nums.size() < 3 ) return res;
//         sort(nums.begin(), nums.end());
//         for(int index = 0; index < nums.size(); index++){
//             // find two other elements add up to 0 with this target
//             while( index >0 && nums[index] == nums[index-1]) index++; // rule out the same target
//             int l = index+1, r = nums.size()-1;
//             while( l < r ){
//                 int sum = nums[index] + nums[l] + nums[r];
//                 if( sum == 0 ){
//                     int result[3] = {nums[index], nums[l], nums[r]};
//                     res.push_back(vector<int>(result, result+3));
//                     l++, r--;
//                     // when adding to this target, rule out all the same numbers
//                     while( nums[l] == nums[l-1] ) l++;
//                     while( nums[r] == nums[r+1] ) r--;
//                 }
//                 else if( sum > 0 ) r--;
//                 else l++;
//             }
//         }
//         return res;
//     }
// };

// 108 ms, faster than 47.94% 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if( nums.size() < 3 ) return res;
        sort( nums.begin(), nums.end() );
        for(int i = 0; i < nums.size(); i++ ){
            if( i > 0 && nums[i] == nums[i-1] ) continue;
            int l = i+1, r = nums.size()-1;
            while( l < r ){
                if( (l > i+1 && nums[l] > nums[l-1]) || (l == i+1) ){ // this is the same as the while loop in line 19
                    int sum = nums[l]+nums[r];
                    if( sum == -nums[i] ){
                        int result[3] = {nums[i], nums[l], nums[r]};
                        res.push_back(vector<int>(result, result+3));
                        l++, r--;
                    }
                    else if( sum < -nums[i] ) l++;
                    else r--; // this is same as the while loop in line 20
                }
                else
                    l++;
            }
        }
        return res;
    }
};