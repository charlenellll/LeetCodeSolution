class Solution {
private:
    vector<int> memo;
    
    int max3(int a, int b, int c){
        return max( a, max(b,c) );
    }
    // Divide n (into at least two part) and calculate the greatest product
    int breakIntegr(int n){
         if(n == 1)
             return 1;
        
        if(memo[n] != -1)
            return memo[n];
        
        int res = -1
        for(int i = 1; i <= n-1; i++)
            // i + (n-i)
            res = max3( res, i*(n-i), i * breakInteger(n-i));
        memo[n] = res;
        
        return res;
    }
public:
    int integerBreak(int n) {
        assert( n >= 1 );
        memo = vector<int>(n+1, -1);
        return breakInteger(n);
    }
};