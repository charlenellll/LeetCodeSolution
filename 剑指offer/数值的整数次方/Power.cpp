// 运行时间：3ms 占用内存：472k
class Solution {
public:
    double Power(double base, int exponent) {
        int res = 1;
        for(int i = 1; i <= abs(exponent); i++ )
            res *= base;
        if( exponent > 0 ) return res;
        else return (double)1/res;
    }
};