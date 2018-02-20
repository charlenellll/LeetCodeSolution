/* Follow-up: No loop or recursion
 * It's all about MATH */

// 74ms, 19%

class Solution {
public:
    bool isPowerOfThree(int n) {
        double res = log10(n) / log10(3);
        return res == int(res);
    }
};

/* iteration and recursions */

// 63ms, 30%
// simplified recursion

class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && ( (n == 1) || (n % 3 == 0) && isPowerOfThree(n/3));
    }
};

// 69ms, 21%
// simplified iteration
class Solution {
public:
    bool isPowerOfThree(int n) {
        if( n <= 0 ) return false;
        while( n % 3 == 0 ) n /= 3;
        return n == 1;
    }
};

// 65 ms, 20%
// Brutal-force recursive
class Solution {
public:
    bool isPowerOfThree(int n) {
        if( n == 1 ) return true;
        if( n == 0 || n == 2 ) return false;
        if( n % 3 != 0 ) return false;
        else return isPowerOfThree( n/3 );
    }
};

// 75ms, 16% 
// Brutal-force iterative
class Solution {
public:
    bool isPowerOfThree(int n) {
        if( n <= 0 ) return false;
        if( n == 1 ) return true;
        while( n > 1 ){
            if( n % 3 != 0 )
                return false;
            n /= 3;
        }
        return n == 1;
    }
};