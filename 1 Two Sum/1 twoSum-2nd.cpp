// 8 ms, faster than 92.48%

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        if( nums.size() <= 1 ) return result;
        unordered_map<int,int> recordIndex;
        for(int i = 0; i < nums.size(); i++){
            if( recordIndex.find( target - nums[i]) != recordIndex.end() ){
                int res[2] = {i, recordIndex[target-nums[i]]};
                return vector<int>(res, res+2);
            }
            recordIndex[nums[i]] = i;
        }
        return result;
    }
};