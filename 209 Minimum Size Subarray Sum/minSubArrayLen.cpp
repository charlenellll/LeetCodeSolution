class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        // Set nums[l,r] as the sliding window     
        int l = 0, r = -1;
        int sum = 0;
        int res = nums.size() + 1;
        
        while(l < nums.size()){
            if(r+1 < nums.size() && sum < s)
                sum += nums[++r];
            else // If r+1 is out of boundary, we can only slide l index
                sum -= nums[l++];
            if(sum >= s)
                res = min(res, r-l+1);
        }
        
        if(res == nums.size() + 1)
            return 0;
        
        return res;
    }
};


// 2nd round
// 8 ms, faster than 96.46% 
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        //first expand to right so subarray sum > s, then shrink the left to make window smaller
        if( nums.size() == 0 ) return 0;
        int l = 0, r = -1, sum = 0, size = nums.size()+1; // nums[l..r] in the window
        while( l < nums.size() ){
            if( r+1 < nums.size() && sum < s ) 
                sum += nums[++r];
            else 
                sum -= nums[l++]; // If we cannot slide r, we can only slide l
            if( sum >= s )
                size = min(size, r-l+1);
        }
        if( size == nums.size() + 1 ) 
            return 0; //If no solution exists
        return size;
    }
};