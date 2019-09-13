// Optimization: Early-stopping
// Optimized only 2 lines
// 8 ms, faster than 98.08% 

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if( nums.size() < 4 ) return res;
        sort( nums.begin(), nums.end() );
        int n = nums.size();
        for(int i = 0; i < n; i++ ){ // ----4sum part!!-----
            // break into 3sum problem
            if( i > 0 && nums[i] == nums[i-1] ) continue;// remove duplicate target1
            int target1 = target - nums[i]; // 3sum=target1
            for(int j = i+1; j < n; j++){ // ----3sum part!!----
                // break into 2sum problem
                if( j > i+1 && nums[j] == nums[j-1] ) continue; // remove duplicate target2 
                int target2 = target1 - nums[j];
                if( nums[n-1] + nums[n-2] < target2 ) continue; //target1-nums[j] could be smaller -----optimization
                if( j+2 < n && nums[j+1] + nums[j+2] > target2 ) break; // no solution left in this 3sum problem, but still solutions after switching 3sum problem---optimization
                int l = j + 1, r = n-1;
                while(l < r){ // ----2sum part !!----
                    // remove duplicate when combine two numbers
                    if( l == j + 1 || (l > j+1 && nums[l] > nums[l-1] ) ){ 
                        int sum = nums[l]+nums[r];
                        if( sum == target2 ){
                            int result[4] = {nums[i], nums[j], nums[l], nums[r]};
                            res.push_back(vector<int>(result, result+4));
                            l++, r--;
                        }
                        else if( sum < target2 ) l++;
                        else r--;
                    }
                    else
                        l++;
                }
            }
        }
        return res;
    }
};


// 36 ms, faster than 60.61%
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if( nums.size() < 4 ) return res;
        sort( nums.begin(), nums.end() );
        // break into 3sum problem
        for(int i = 0; i < nums.size(); i++ ){
            if( i > 0 && nums[i] == nums[i-1] ) continue;// remove duplicate target1
            int target1 = target - nums[i]; // 3sum=target1
            // break into 2sum problem
            for(int j = i+1; j < nums.size(); j++){
                if( j > i+1 && nums[j] == nums[j-1] ) continue; // remove duplicate target2
                int target2 = target1 - nums[j];
                int l = j + 1, r = nums.size()-1;
                while(l < r){
                    // remove duplicate when combine two numbers
                    if( l == j + 1 || (l > j+1 && nums[l] > nums[l-1] ) ){ 
                        int sum = nums[l]+nums[r];
                        if( sum == target2 ){
                            int result[4] = {nums[i], nums[j], nums[l], nums[r]};
                            res.push_back(vector<int>(result, result+4));
                            l++, r--;
                        }
                        else if( sum < target2 ) l++;
                        else r--;
                    }
                    else
                        l++;
                }
            }
        }
        return res;
    }
};