// 8ms, beats 27.75% but most people have the same runtime as me and our time is the same, so it's not slow
// O(N) time

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if( prices.size() <= 1 ) return 0;
        int maxPro = 0, minDay = prices[0];
        for(int i = 1; i < prices.size(); i++ ){
            minDay = min(minDay, prices[i]);
            maxPro = max(maxPro, prices[i] - minDay);
        }
        return maxPro;
    }
};