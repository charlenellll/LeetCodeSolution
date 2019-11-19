// 1. 对每个小于n的数判断isPrime O(N^2)time-> TLE
class Solution {
public:
    int countPrimes(int n) {
        if( n <= 2 ) return 0;
        int count = 1;
        for(int i = 3; i < n; i++ ){
            bool isPrime = true;
            for(int k = 2; k*k <= i; k++ )
                if( i % k == 0 )
                    isPrime = false;
            if( isPrime ) count++;
        }
        return count;
    }
};

// 2. 从小数到大将自己的倍数的isPrime置为false由此来判断质数, O(n) space O(n^2) time but early stopping
// 156 ms, faster than 28.57%
class Solution {
public:
    int countPrimes(int n) {
        if( n <= 2 ) return 0;
        vector<bool> isPrime(n+1, true);
        int cnt = 0;
        for(int i = 2; i < n; i++ ){
            if( isPrime[i] ) cnt++;
            if( i > sqrt(n) ) continue;
            for(int j = i*i; j <= n; j+=i )
                isPrime[j] = false;
        }
        return cnt;
    }
};

// 3. 只遍历奇数
// 64 ms, faster than 61.29%
class Solution {
public:
    int countPrimes(int n) {
        if( n <= 2 ) return 0;
        vector<bool> isPrime(n+1, true);
        int cnt = 1;
        for(int i = 3; i < n; i+=2 ){
            if( isPrime[i] ) cnt++;
            if( i > sqrt(n) ) continue;
            for(int j = i*i; j <= n; j+=i )
                isPrime[j] = false;
        }
        return cnt;
    }
};

// 4. 把最内侧置为非质数的循环放到if(isPrime[i])中，因为如果它非质数，它的倍数也早就被同时置为非质数了
// 40 ms, faster than 73.68%
class Solution {
public:
    int countPrimes(int n) {
        if( n <= 2 ) return 0;
        vector<bool> isPrime(n+1, true);
        int cnt = 1;
        for(int i = 3; i < n; i+=2 ){
            if( isPrime[i] ) {
                cnt++;
                if( i > sqrt(n) ) continue;
                for(int j = i*i; j <= n; j+=i )
                    isPrime[j] = false;
            }
        }
        return cnt;
    }
};