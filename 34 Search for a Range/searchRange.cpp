// 12ms

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if( n == 0 ) return vector<int>{-1,-1};
        int res = binarySearch(nums, 0, n-1, target);
        if( res == -1 )
            return vector<int>{-1,-1};
        else{
            int left = res, right = res;
            while( nums[left] == target && left >= 0 ) left--;
            while( nums[right] == target && right <= n-1 ) right++;
            return vector<int>{left+1, right-1};
        }
    }
    
    int binarySearch(const vector<int>& nums, int left, int right, int target){
        if( left == right && nums[left] != target ) return -1;
        int mid = left + (right - left)/2;
        if( target == nums[mid] )
            return mid;
        else if( target < nums[mid] )
            return binarySearch( nums, left, mid, target);
        else
            return binarySearch(nums, mid+1, right, target);
    }
};

// sample 9ms code:
// use lower_bound and upper_bound function is faster

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return{ -1, -1 };

    auto iter1 = lower_bound(nums.begin(), nums.end(), target);
    auto iter2 = upper_bound(nums.begin(), nums.end(), target);

    if (iter1 == nums.end()) return{ -1, -1 };

    if ((*iter1) != target) return{ -1, -1 };
    vector<int> tmp(2, 0);
    tmp[0] = iter1 - nums.begin();

    --iter2;
    tmp[1] = iter2 - nums.begin();
    return tmp;
    }
};