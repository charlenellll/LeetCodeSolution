// solution 1.0

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

// 2nd round practice
// solution 1.1
// Runtime: 4 ms, faster than 84.20%; Memory Usage: 8.8 MB, less than 65.22%
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // scan them from tail to head
        int p = m-1, q = n-1;
        for(int i = m+n-1; i >= 0 ; i-- ){
            if( p < 0 || q < 0 ) break;
            if( nums1[p] >= nums2[q] ) nums1[i] = nums1[p--];
            else nums1[i] = nums2[q--];
        }
        if( p < 0 ){
            for(int i = q; i >= 0; i--) nums1[i] = nums2[q--];
        }
    }
};

// solution 1.2
// optimization based on solution 1.0
// Runtime: 4 ms, faster than 84.20%; Memory Usage: 8.6 MB, less than 93.48%
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // scan them from tail to head
        int p = m-1, q = n-1;
        for(int i = m+n-1; i >= 0 ; i-- ){
            if( q < 0 ) break;
            if( p < 0 ) nums1[i] = nums2[q--];
            else if( nums1[p] >= nums2[q] ) nums1[i] = nums1[p--];
            else nums1[i] = nums2[q--];
        }
    }
};