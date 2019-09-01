// 32 ms, faster than 24.25%

class Solution {
private:
    int findKth(vector<int>& nums, int l, int r, int k){
        // nums[l]=v, nums[l+1..gr]>v, nums[gr+1..i-1]<=v, nums[i..r] unknown
        int gr = l, v = nums[l], i = l+1;
        while( i <= r ){
            if( nums[i] > v ) swap(nums[++gr], nums[i++]);
            else i++;
        }
        swap(nums[l], nums[gr]);
        if( gr == k-1 ) return nums[gr];
        else if( gr > k-1 ) return findKth(nums, l, gr-1, k);
        else return findKth(nums, gr+1, r, k);
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Quick Sort nums in descending order
        return findKth(nums, 0, nums.size()-1, k);
    }
};