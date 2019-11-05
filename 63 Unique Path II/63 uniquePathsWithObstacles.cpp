// 4 ms, faster than 74.79%
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if( obstacleGrid.size() == 0 || (obstacleGrid.size() != 0 && obstacleGrid[0].size() == 0 )) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<long long>> numPath(m, vector<long long>(n, 0));//num of unique path to this grid //有test case有溢出问题因此改成long long
        numPath[0][0] = (obstacleGrid[0][0] == 0 ) ? 1 : 0;
        for(int i = 1; i < m; i++ ){ //初始化其实也可以写进后面的循环里
            if( obstacleGrid[i][0] != 1 && obstacleGrid[i-1][0] != 1 ) numPath[i][0] = 1;
            else break;
        }
        for(int j = 1; j < n; j++ ){
            if( obstacleGrid[0][j] != 1 && obstacleGrid[0][j-1] != 1 ) numPath[0][j] = 1;
            else break;
        }
        
        for( int i = 1; i < m; i++ )
            for( int j = 1; j < n; j++)
                if( obstacleGrid[i][j] == 0 ) numPath[i][j] = numPath[i][j-1] + numPath[i-1][j];
        return numPath[m-1][n-1];
    }
};