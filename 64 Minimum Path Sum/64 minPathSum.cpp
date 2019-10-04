// 8 ms, faster than 87.25%
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {//minSum表示到i,j位置处的最小sum
        // minSum[i][j] = grid[i][j] + min(minSum[i-1][j], minSum[i][j-1]) 在二者都是0-based情况下
        if( grid.size() == 0 || (grid.size() != 0 && grid[0].size() == 0 )) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> minSum(m, vector<int>(n, 0)); //实际上需要用1-based
        minSum[0][0] = grid[0][0];
        for(int j = 1; j < n; j++ )
            minSum[0][j] = grid[0][j] + minSum[0][j-1];
        for(int i = 1; i < m; i++)
            minSum[i][0] = grid[i][0] + minSum[i-1][0];
        
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                minSum[i][j] = grid[i][j] + min(minSum[i-1][j], minSum[i][j-1]);
        return minSum[m-1][n-1];
    }
};