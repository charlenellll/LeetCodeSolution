// (optimizaiton 3): I realized that I forgot to put everything inside the if-statement
// It really speeds up my solution.
// 20ms, 87.67%
class Solution {
public:
    int countPrimes(int n) {
        if( n <= 2 ) return 0;
        int cnt = 1;
        int upper = sqrt(n);
        vector<bool> isPrime(n, true);
        for(int i = 3; i < n; i+=2 ){
            if( isPrime[i] ){ // put everythong inside this if-statement
                cnt++;
                if( i > upper) continue;
                for(int j = i * i; j <= n; j += i)
                    isPrime[j] = false;
            } 
        }
        return cnt;
    }
};

// Optimization 2: only traverse the odd numbers
// 27ms, beats 73.9%

class Solution {
public:
    int countPrimes(int n) {
        if( n <= 2 ) return 0;
        int cnt = 1;
        int upper = sqrt(n);
        vector<bool> isPrime(n+1, true);
        for(int i = 3; i < n; i+=2 ){
            if( isPrime[i] ) cnt++;
            if( i > upper) continue;
            for(int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
        return cnt;
    }
};

// Optimization 1: change the bound of loop to sqrt(n)
// - of course after it we still need to traverse and count primes so this bound is not typically in the outer loop
// 57ms, beats 27.5%

class Solution {
public:
    int countPrimes(int n) {
        if( n <= 1 ) return 0;
        int cnt = 0;
        int upper = sqrt(n);
        vector<bool> isPrime(n+1, true);
        for(int i = 2; i < n; i++ ){
            if( isPrime[i] ) cnt++;
            if( i > upper) continue;
            for(int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
        return cnt;
    }
};



// Normal solution: brutal-force
// inpit:1500000: TLE!

class Solution {
private:
    bool isPrime(int n){
        if( n <= 1 ) return false;
        for(int i = 2; i <= sqrt(n); i++ ){ //here i should choose either i <= sqrt(n) or i < n/2+1, if i < sqrt(n)+1 there will be error when n=2
            if( n % i == 0 ) return false;
        }
        return true;
    }
public:
    int countPrimes(int n) {
        int cnt = 0;
        for(int i = 2; i < n; i++ ){
            if( isPrime(i) ) cnt++;
        }
        return cnt;
    }
};