// 7ms

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        if( k <= 0 || (n == 0 && k != 0) ) return false;
        int sum = 0;
        for( int i = 0; i < n; i++ )
            sum += nums[i];
        if( sum%k != 0 ) return false;
        vector<bool> visited(n, 0);
        sort( nums.begin(), nums.end(), greater<int>() );
        return findPartition(nums, k, 0, 0, sum/k, visited);
    }
    
    bool findPartition(const vector<int>& nums, int k, int start, int curSum, int target, vector<bool>& visited){
        if( k == 1 ) return true;
        if( curSum > target ) return false;
        else if( curSum == target ) return findPartition(nums, k-1, 0, 0, target, visited);
        else{ // curSum < target
            for( int i = start; i < nums.size(); i++ )
                if( !visited[i] ){
                    visited[i] = true;
                    if( findPartition(nums, k, i+1, curSum+nums[i], target, visited) ) return true;
                    else visited[i] = false;
                }
            return false;
        }
    }
};


// Don't know why but this is a little bit faster
// 6ms
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(int num:nums)sum+=num;
        if(k <= 0 || sum%k != 0)return false;
        vector<int> visited(nums.size(), 0);
        return canPartition(nums, visited, 0, k, 0, 0, sum/k);
    }

    bool canPartition(vector<int>& nums, vector<int>& visited, int start_index, int k, int cur_sum, int cur_num, int target){
        if(k==1)return true;
        if(cur_sum > target) return false;
        if(cur_sum == target && cur_num >0 )return canPartition(nums, visited, 0, k-1, 0, 0, target);
        for(int i = start_index; i<nums.size(); i++){
            if(!visited[i]){
                visited[i] = 1;
                if(canPartition(nums, visited, i+1, k, cur_sum + nums[i], cur_num++, target))return true;
                visited[i] = 0;
            }
        }
        return false;
    }
};