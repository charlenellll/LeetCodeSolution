// Solution 2： O(logN) time
// 运行时间：3ms 占用内存：484k
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int cnt = 0, n = data.size();
        int l = 0, r = n-1, mid = -1;
        while( l <= r ){
            mid = l + (r - l)/2;
            if( data[mid] == k ) break;
            else if( data[mid] < k ) l = mid+1;
            else r = mid-1;
        }
        if( mid != -1 ){
            for(int i = mid; i >= 0 && data[i] == k ; i--) cnt++;
            for(int i = mid+1; i < n && data[i] == k; i++) cnt++;
        }
        return cnt;
    }
};

// Solution 1： O(n) time
// 运行时间：4ms 占用内存：496k
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int cnt = 0, n = data.size();
        if( n == 0 || k < data[0] || k > data[n-1] ) return cnt;
        for(int i = 0; i < n && data[i] <= k ; i++ )
            if( data[i] == k )
                cnt++;
        return cnt;
    }
};