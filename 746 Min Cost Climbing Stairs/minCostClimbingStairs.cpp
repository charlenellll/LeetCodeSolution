// Dynamic programming: O(n) Time O(1) Space
// 15 ms

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if( n == 0 ) return 0;
        if( n == 1 ) return cost[0];
        if( n == 2 ) return min(cost[0],cost[1]);
        for(int i = 2; i < n; i++ ){
            cost[i] = min(cost[i]+cost[i-1], cost[i]+cost[i-2]);
        }
        return min(cost[n-1], cost[n-2]);
    }
};