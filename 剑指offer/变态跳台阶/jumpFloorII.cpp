// 运行时间：3ms 占用内存：480k
class Solution {
public:
    int jumpFloorII(int number) {
        if( number == 0 ) return 0;
        int cnt = 1;
        for(int i = 2; i <= number; i++ )
            cnt = 2 * cnt;
        return cnt;
    }
};

// num[i] = num[i-1]一步 + num[i-2]两步 + ... + num[0]n步
// num[1] = 1;
// num[2] = 2;
// num[3] = 1 + 1 + 2 = 4;
// num[4] = 1 + 1 + 2 + 4 = 8;
// num[5] = 1 + 1 + 2 + 4 + 8 = 16;
// 归纳可得num[i] = 2(num[i-1])