// S2-2：用c++ stl count函数
// 运行时间：3ms 占用内存：592k
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int n = numbers.size();
        if( n == 0 ) return 0;
        int cnt = 1, candidate = numbers[0];
        for(int i = 1; i < n; i++ ){
            if( cnt <= 0 ){
                candidate = numbers[i];
                cnt = 1;
            }
            else if( numbers[i] == candidate ) cnt++;
            else cnt--;
        }
        int canCnt = count(numbers.begin(), numbers.end(), candidate);
        if( canCnt > n/2 ) return candidate;
        return 0;
    }
};

// Solution 1: 排序 O(NlogN)
// S1-2: 用c++ stl的count()函数
// 运行时间：4ms 占用内存：480k
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int n = numbers.size();
        if( n == 0 ) return 0;
        sort(numbers.begin(), numbers.end());
        int candidate = numbers[ n/2 ];
        int cnt = count(numbers.begin(), numbers.end(), candidate);
        if( cnt > n/2 ) return candidate;
        else return 0;
    }
};

// S1-1: 自己count
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

// Solution 2: 参考牛客上的解法，记录出现次数，O(N) time

// S2-1：自己count candidate个数，理论上O(N)但实际比上面的办法慢了
// 运行时间：5ms 占用内存：460k
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int n = numbers.size();
        if( n == 0 ) return 0;
        int cnt = 1, candidate = numbers[0];
        for(int i = 1; i < n; i++ ){
            if( cnt <= 0 ){
                candidate = numbers[i];
                cnt = 1;
            }
            else if( numbers[i] == candidate ) cnt++;
            else cnt--;
        }
        int canCnt = 0;
        for(int i = 0 ; i < n ; i++)
            if( numbers[i] == candidate )
                canCnt++;
        if( canCnt > n/2 ) return candidate;
        return 0;
    }
};