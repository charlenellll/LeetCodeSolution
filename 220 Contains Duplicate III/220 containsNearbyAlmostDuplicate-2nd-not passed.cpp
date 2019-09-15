// 最后一个test case不能通过

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if( nums.size() <= 1 || k < 1 || t < 0 ) return false;
        unordered_set<int> record; // [i-k..i-1] w.r.t new i, size is k
        for(int i = 0; i < nums.size(); i++ ){
            for( auto value: record ){
                long long diff = (long long)nums[i] - value; // 躲避越界问题
                if( (diff <=  0 && ((-diff) <= t)) || (diff > 0 && diff <= t ) ) return true; //越界后不能用abs()了
            }
            if( record.size() == k ) record.erase(nums[i-k]);
            record.insert(nums[i]);
        }
        return false;
    }
};