// 4ms 608K
class Solution {
private:
    vector<int> memo; //memo[i]存放数列的第i个数（1-based）
public:
    int Fibonacci(int n) {
        if( memo.size() > n ) return memo[n];
        memo = vector<int>(n+1, 0);
        memo[1] = 1;
        memo[2] = 1;
        for(int i = 3; i <= n; i++)
            memo[i] = memo[i-1] + memo[i-2];
        return memo[n];
    }
};