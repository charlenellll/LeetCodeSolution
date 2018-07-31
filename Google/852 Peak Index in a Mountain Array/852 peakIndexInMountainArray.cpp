// 1. 根据题目特性遍历数组
// 8 ms, beats 98.76%
// O(N) time, O(1) space

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        for(int i = 1; i < A.size(); i++){
            if( A[i] > A[i+1] ) return i;
        }
    }
};

// 这个凭直觉的解法充分利用了题目条件了！已经很棒了！




// --------------------------------------------
// 2. Binary Search: slower on this problem, 不好！
// 16 ms, beats 2.9%
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int l = 0, r = A.size()-1;
        while( l <= r){
            if( l == r ) return l;
            int mid = l + (r-l)/2;
            if( A[mid] > A[mid+1] && A[mid] > A[mid-1]) return mid;
            if( A[mid] < A[mid+1] && A[mid] > A[mid-1] ) l = mid+1;
            if( A[mid] < A[mid-1] && A[mid] > A[mid+1]) r = mid-1;
        }
    }
};

//-----------------------------------------------------
// 4 ms 神sample code:
class Solution {
 public:
  int peakIndexInMountainArray(vector<int>& A) {
    int left = 1, right = A.size() - 1;
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (A[mid] <= A[mid + 1]) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return left;
  }
};
static int x = [](){ // 加速c++输入输出流, 见博客https://www.cnblogs.com/PrayG/p/5749832.html
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();