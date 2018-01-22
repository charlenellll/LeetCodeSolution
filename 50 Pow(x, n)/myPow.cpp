// We can see that where are some abnormal test case

// Runtime error if x * pow(x, n-1) each time: O(N)
// If we use binary divison of n each time, this problem will be solved (of course we shoud consider if n is even or odd)

	0.00001
	2147483647

// -214783648 is the expression of INT_MIN, it is an illegal expression
// INT_MIN = - INT_MAX - 1
// So x^(INT_MIN) = 1.0 / x^(INT_MAX + 1)

	2.00000
	-2147483648

// Optimized: O(logN)
// 6ms
class Solution {
public:
    double myPow(double x, int n) {
        if( n == 0 || x == 1 ) return 1;
        if( n == 1 ) return x;

        // // This line is crucial for the above test case!
        // if( n == INT_MIN )
        //     return 1.0 / (x * myPow(x, INT_MAX));

      	// This will make use of this step and also avoid INT_MIN! and faster!:
        if(n<0)
            return (1/x)*myPow(1/x,-(n+1));
        else if( n % 2 == 1)
            return x * myPow(x * x, n/2);
        else
            return myPow( x*x, n/2);        
    }
};


// O(logN)
class Solution {
public:
    double myPow(double x, int n) {
        if( n == 0 || x == 1 ) return 1;
        if( n == 1 ) return x;

        // This line is crucial for the above test case!
        if( n == INT_MIN )
            return 1.0 / (x * myPow(x, INT_MAX));
        if( n < 0 )
            return 1.0 / myPow(x, -n);
        // This verison can still make use of this step and also avoid INT_MIN! and faster!:
        // if(n<0){
        //     return (1/x)*myPow(1/x,-(n+1));
        // }
        // It originates from:
        // suppose n = INT_MIN, y = INT_MAX, y = -(n+1) vise versa
        // x^n = x^-(y+1) = 1/x ^ y+1 = 1/x ^ -(n+1)+1
        else if( n % 2 == 1)
            return x * myPow(x * x, n/2);
        else
            return myPow( x*x, n/2);        
    }
};


// iterative way: from internet
// 10ms
// O(logN)
class Solution {
public:
    // n的二进制位上的, 每一个都是2的幂数, 翻倍相乘；多个结果相乘即可。
    double myPow(double x, int n) {
        long long abs_n = abs((long long)n);
        double sum = 1.0;
        long long i = 1;
        double i_sum = x;
        while (abs_n > 0) {
            if (i & abs_n) {
                sum *= i_sum;
                abs_n -= i;
            }
            i_sum *= i_sum;
            i <<= 1;
        }
        if (n > 0) {
            return sum;
        } else {
            return 1/sum;
        }
    }
};