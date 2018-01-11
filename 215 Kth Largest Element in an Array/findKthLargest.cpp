class Solution {
private:
    int findKth(vector<int>& nums, int k, int l, int r){
        
        // nums[l..border] > pivot, nums[border+1..i-1] <= pivot, nums[i..r] unsorted
        int border = l;
        int pivot = nums[l];
        
        for(int i = l+1; i <= r; i++  )            
            if( nums[i] > pivot )
                swap( nums[i], nums[++border]);
        swap(nums[l], nums[border]);
        // nums[l..border-1] > pivot, nums[border] == pivot， nums[border..r] <= pivot 
        
        if( border < k-1 )
            // find in nums[border+1..r]
            return findKth( nums, k, border+1, r);
        else if( border > k-1 )
            // find in nums[l..border]
            return findKth( nums, k, l, border);
        else // the border is the Kth largest element
            return nums[border];    
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKth(nums, k, 0, nums.size()-1);     
    }
};