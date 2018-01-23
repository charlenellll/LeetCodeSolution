// 7ms
// collider pointer

class Solution {
public:
    bool judgeSquareSum(int c) {
        if( c < 0 ) return false;
        int a = 0, b = int(sqrt(c));
        while( a <= b ){
            int sum = a*a + b*b;
            if( sum == c )
                return true;
            else if( sum < c )
                a++;
            else
                b--;
        }
        return false;
    }
};


// 10ms
// scan through the first half of the input + find if the complement of i*i is square number

class Solution {
public:
    bool judgeSquareSum(int c) {
        if( c < 0 ) return false;
        for( int i = 0; i <= sqrt(c); i++ ){
            int tmp = c - i*i;
            if( int(sqrt(tmp)) * int(sqrt(tmp)) == tmp )
                return true;
        }
        return false;
    }
};