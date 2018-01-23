// Binary Search

class Solution {
public:
    bool isPerfectSquare(int num) {
        if( num < 1 ) return false;
        if( num == 1 ) return true;
        // we have to use long here to prevent overflow
        long long left = 1, right = num;
        while( left <= right ){
        	// use long type here because many inputs are extremely large
            long long mid = left+(right-left)/2;
            long long t = mid*mid;
            if( t == num )
                return true;
            else if( t > num )
                right = mid-1;
            else // t < num
                left = mid + 1;
        }
        return false;
    }
};


// Normal Solution O(N)
// 701ms

class Solution {
public:
    bool isPerfectSquare(int num) {
        if( num < 1 ) return false;
        for( int i = 1; i <= (num/2+1); i++ )
            if( num == i*i ) return true; 
        return false;
    }
};