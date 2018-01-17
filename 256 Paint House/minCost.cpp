// 6ms

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        
        // for the i-th house, rBest denotes the min cost to paint (i-1)th house red, same for bBest and gBest
        int rBest = 0, bBest = 0, gBest = 0;
        for( int i = 0; i < costs.size(); i++ ){
            int r = costs[i][0], b = costs[i][1], g = costs[i][2];
            r = r + min(bBest, gBest);
            b = b + min(rBest, gBest);
            g = g + min(rBest, bBest);
            rBest = r, bBest = b, gBest = g;
        }
        return min(rBest, min(gBest, bBest));
    }
};

// or I can do it inplace in costs array

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        
        if( costs.size() == 0 ) return 0;
        // manipulate the result on costs array
        int n = costs.size();
        for( int i = 1; i < n; i++ ){
            costs[i][0] = costs[i][0] + min(costs[i-1][1], costs[i-1][2]);
            costs[i][1] = costs[i][1] + min(costs[i-1][0], costs[i-1][2]);
            costs[i][2] = costs[i][2] + min(costs[i-1][1], costs[i-1][0]);
        }
        return min(costs[n-1][0], min(costs[n-1][1], costs[n-1][2]));
    }
};


// 3ms sample code

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        if (n == 0) {
            return 0;
        }
        for (int i = 1; i < n; ++i) {
            costs[i][0] += min(costs[i - 1][1], costs[i - 1][2]);
            costs[i][1] += min(costs[i - 1][0], costs[i - 1][2]);
            costs[i][2] += min(costs[i - 1][0], costs[i - 1][1]);
        }
        
        // don't know why it can use min({a,b,c})
        return min({costs[n - 1][0], costs[n - 1][1], costs[n - 1][2]});
    }
};