// Still wrong in some test cases!!
// Hven't solved this problem

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int total = m+n;
        if( total % 2 == 1 )
            return findKth(nums1, 0, m, nums2, 0, n, total/2+1);
        else
            return (findKth(nums1, 0, m, nums2, 0, n, total/2) + findKth(nums1, 0, m, nums2, 0, n, total/2+1))/2;
    }
    
    double findKth(vector<int>& nums1, int start1, int m, vector<int>& nums2, int start2, int n, int k){
        if( m > n )
            return findKth(nums2, start2, n, nums1, start1, m, k);
        if( m == 0 )
            return nums2[k-1];
        if( k == 1 )
            return min(nums1[start1], nums2[start2]);
        // avoid pb == 0
        if( start1 + k/2 == m )
            return nums1[start1 + k/2];
                // not start1 + min(k/2, m)!
        int pa = min(start1 + k/2, m), pb = start2 + k - pa;
        if( nums1[pa-1] < nums2[pb-1] )
            return findKth(nums1, pa, m-pa, nums2, start2, n, k-pa);
        else if( nums1[pa-1] > nums2[pb-1] )
            return findKth(nums1, start1, m, nums2, pb, n-pb, k-pb);
        else // A[pa-1] == B[pb-1]
            return (double)nums1[pa-1];
    }
};