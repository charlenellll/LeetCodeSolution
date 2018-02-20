// 2. Really delicate design
// O(N) time, O(1) space
// 138ms, 42.6%

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        
        for(int i = 0; i < n; i++){
            int pos = abs(nums[i])-1; // since the position is 0-based
            nums[pos] = nums[pos] > 0? -nums[pos] : nums[pos];
        }
        for( int i = 0 ; i < n; i++){
            if( nums[i] > 0 ) // the number i+1 didn't show up in the first pass
                res.push_back(i+1);
        }
        return res;
    }
};


// 1. Brutal-force, without extra space
// O(NlogN) time for the sort() function, O(1) space
// 164ms, 14.61%

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        if( nums.size() == 0 ) return res;
        sort( nums.begin(), nums.end());
        int number = 1;
        for( int i = 0; i < nums.size(); i++){
            while( nums[i] > number ){
                res.push_back( number );
                number++;
            }
            if( nums[i] == number ) number++;
        }
        while( number <= nums.size() ) res.push_back( number++ );
        return res;
    }
};