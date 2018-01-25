class Solution {
public:
    bool isPalindrome(int x) {

        if ( x < 0 ) return false;

        // reverse half of the number
        // the exit condition is y >= x
        // so that overflow is avoided.
        int y = 0;
        while (y < x) {
            y = y * 10 + (x % 10);
            if (x == y)  // to check numbers with odd digits
                return true;
            x /= 10;
        }
        return x == y; // to check numbers with even digits
    }
};

// Wrong code:
// class Solution {
// public:
//     bool isPalindrome(int x) {
//         if( x < 0 ) return false;
//         int bit = 0, divisor = x;
//         while( divisor > 0 ){
//             divisor /= 10;
//             bit++;
//         }
//         int curBit = bit;
//         divisor = x;
//         while( curBit >= bit/2 ){
//             int firstBit = divisor / pow(10, curBit - 1);
//             if( divisor % 10 != firstBit)
//                 return false;
//             divisor = (divisor - firstBit * pow(10, curBit - 1)) / 10;
//             curBit -= 2;
//         }
//         return true;
//     }
// };

// sample 142ms code

class Solution {
public:
    bool isPalindrome(int x) {
        if(x == 0) return true;
        if(x % 10 == 0) return false;
        int sum = 0;
        while(x > 0){
            sum = sum * 10 + x % 10;
            if(sum == x) return true;
            x /= 10;
            if(sum == x) return true;
        }
        return false;
    }
};

// sample 42ms code

static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        //int b = 10; while (x / b) b *= 10; b /= 10;
        //if (x/ b != x % 10) return false;
        //x = (x % b) / 10;
        int l = x, r = 0;
        while (l) r = r * 10 + l % 10, l /= 10;
        return r == x;
    }
};