// Clearer version of Solution 2
// 28 ms, faster than 86.09%
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if( nums.size() <= 1 || k < 1 ) return false; // 2 distinct indices
        unordered_set<int> record; // stores values in nums[i-k..i-1] (keep the index dist with i) <= k
        for(int i = 0; i < nums.size(); i++ ){
            if( record.find(nums[i]) != record.end() ) return true;
            record.insert(nums[i]); // need to insert before delete because it influence the size of the set
            if( record.size() == k+1 ) record.erase(nums[i-k]);
        }
        return false;
    }
};

// Solution 2: unordered_set - but this one is kind of messy to think about
// O(n) time, O(k) space
// 32 ms, faster than 62.71% 
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if( nums.size() <= 1 || k < 1 ) return false; // 2 distinct indices
        unordered_set<int> record; // stores values in nums[i-k..i-1] (keep the index dist with i) <= k
        for(int i = 0; i < nums.size(); i++ ){
            if( record.find(nums[i]) != record.end() ) return true;
            if( i-k >= 0 ) record.erase( nums[i-k] );
            record.insert(nums[i]); // no need for map cuz once the value shown up the 2nd time, it already returns.
            // In theory we need to insert nums[i] after deleting nums[i-k] in case they are the same and accidentally erased, but this does not influence current test cases
        }
        return false;
    }
};

// Solution 1: sliding window, 最后一个test case TLE了！
// O(nk) time, O(1) space
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if( nums.size() <= 1 ) return false; // 2 distinct indices
        //[i,j] contains at least 2 elements
        for(int i = 0; i < nums.size()-1; i++ )
            for(int j = i + 1; (i+k) >= nums.size() ? j < nums.size() : j <= i + k ; j++ ){ 
                if( nums[i] == nums[j] )
                    return true;
        }
        return false;
    }
};