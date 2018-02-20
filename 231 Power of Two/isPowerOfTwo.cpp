// An amazing solution but only applicable to power of two
//Power of 2 means only one bit of n is ‘1’, so use the trick n&(n-1)==0 to judge whether that is the case
// 5ms
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if( n <= 0 ) return false;
        return (n&(n-1)) == 0;
    }
};

// a simpler version of it is also 5 ms

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 &&  (n&(n-1)) == 0 ;
    }
};

// Do it without loop or recursion:
// 6ms or 9ms, relatively slow

class Solution {
public:
    bool isPowerOfTwo(int n) {
        double power = log10(n) / log10(2);
        return power == int(power);
    }
};

// Iteration
// 6ms

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if( n <= 0 ) return false;
        while( n % 2 == 0 ) n /= 2;
        return n == 1;
    }
};

// Recursion
// 6ms

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if( n == 1 ) return true;
        return n > 0 && (( n % 2 == 0 ) && isPowerOfTwo(n/2));
    }
};