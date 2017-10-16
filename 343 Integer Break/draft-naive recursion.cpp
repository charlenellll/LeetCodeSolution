class Solution {
private:
    int max3(int a, int b, int c){
        return max( a, max(b,c) );
    }
    // Divide n (into at least two part) and calculate the greatest product
    int breakIntegr(int n){
         if(n == 1)
             return 1;
        int res = -1;
        for(int i = 1; i <= n-1; i++)
            // i + (n-i)
            res = max3( res, i*(n-i), i * breakInteger(n-i));
        
        return res;
    }
public:
    int integerBreak(int n) {
        return breakInteger(n);
    }
};