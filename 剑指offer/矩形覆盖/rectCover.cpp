// 运行时间：4ms 占用内存：504k
class Solution {
public:
    int rectCover(int number) {
        if( number <= 1 ) return number;
        vector<int> cnt(number+1, 0);
        cnt[1] = 1;
        cnt[2] = 2;
        for(int i = 3; i <= number; i++ )
            cnt[i] = cnt[i-1] + cnt[i-2];
        return cnt[number];
    }
};