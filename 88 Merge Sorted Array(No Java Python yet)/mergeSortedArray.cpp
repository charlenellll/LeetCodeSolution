class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        if( n == 0 )
            return;
        else if( m == 0 )
            for(int i = n-1; i >= 0; i-- )
                nums1[i] = nums2[i];
        else{
            //Assume both array are in ascending order
            int tail1 = m-1;
            int tail2 = n-1;
            for(int i = m+n-1; i >= 0; i--){
                if( tail2 < 0)
                    return;
                else if( tail1 < 0)
                    nums1[i] = nums2[tail2--];
                else if(nums1[tail1] > nums2[tail2])
                    swap(nums1[i],nums1[tail1--]);
                else
                    nums1[i] = nums2[tail2--];
            }                   
        }
    }
};