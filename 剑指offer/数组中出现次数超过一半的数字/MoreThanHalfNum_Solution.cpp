// 运行时间：4ms 占用内存：456k
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int n = numbers.size();
        if( n == 0 ) return 0;
        sort(numbers.begin(), numbers.end());
        int cnt = 1, mid = n/2, i = mid-1, j = mid+1, candidate = numbers[mid];
        while( i >= 0 && numbers[i] == candidate )
            cnt++, i--;
        while( j < n && numbers[j] == candidate )
            cnt++, j++;
        if( cnt > mid ) return candidate;
        else return 0;
    }
};