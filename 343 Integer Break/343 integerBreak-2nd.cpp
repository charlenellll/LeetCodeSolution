// 0 ms, faster than 100.00% 
class Solution {
public:
    int integerBreak(int n) { //maxP[i] = max(k * maxP[i-k], k * (i-k)) (1 <= k < i, 1 < i <= n ) 可划分前i-k也可不划分！
        vector<int> maxP(n+1, 0);
        maxP[0] = 0;
        maxP[1] = 1;
        for(int i = 2; i <= n; i++ )
            for(int k = 1; k < i; k++ )
                maxP[i] = max(max(k * maxP[i-k], k * (i-k)), maxP[i]); //可划分前i-k也可不划分！
        return maxP[n];
    }
};