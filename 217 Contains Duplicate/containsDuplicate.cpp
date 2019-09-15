// Solution 2
// O(NlogN) time, no extra space
// sort()则是改进的快排算法
// 20 ms, faster than 99.53%
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if( nums.size() <= 1 ) return false;
        sort( nums.begin(), nums.end() );
        for(int i = 1; i < nums.size(); i++ )
            if( nums[i] == nums[i-1] )
                return true;
        return false;
    }
};

// Solution 1
// O(NlogN) time O(N) space
// 40 ms, faster than 62.22% 

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_set<int> record;
        for( int i = 0; i < nums.size(); i++ ){
            
            if( record.find(nums[i]) != record.end() )
                return true;
            record.insert(nums[i]);
        }
        return false;
    }
};