// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

// Recursively
// 2ms, 18.7%

class Solution {
public:
    int guessNumber(int n) {
        return guessNum(1,n);
    }
    int guessNum(int m, int n){
        int mid = m + (n-m)/2;
        int temp = guess(mid);
        if( temp == 0 )
            return mid;
        else if( temp == -1 )
            return guessNum( m, mid-1 );
        else
            return guessNum( mid+1, n);
    }
};

// Iteratively
// 2ms, 18.7%

class Solution {
public:
    int guessNumber(int n) {
        int p = 1, q = n;
        if( guess(p) == 0 ) return p;
        if( guess(q) == 0 ) return q;
        while( p <= q ){
            int mid = p + (q - p) / 2;
            int temp = guess(mid);
            if( temp == 0 ) return mid;
            else if( temp == -1 ) q = mid-1;
            else p = mid+1;
        }
    }
};