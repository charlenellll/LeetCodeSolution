class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
                
        unordered_map<int,int> record;
        for( int i = 0; i < nums.size(); i++){
            
            // In case nums[i] is already in the map and it is part of the solution
            int complement = target - nums[i];
            if(record.find( complement ) != record.end()){
                int res[2] = {i, record[complement]};
                return vector<int>(res, res+2);
            }
            
            record[nums[i]] = i;
        }
        
        // Just in case there is no solution, although the input makes sure there would be 1 solution
        throw invalid_argument(" The input has no solution.");
    }
};