// 0 ms, faster than 100.00%
class Solution {
public:
    int uniquePaths(int m, int n) {
        // numPath[i][j] presents the number of unique paths to grid(i,j)
        vector<vector<int>> numPath(m, vector<int>(n, 0));//只用m*n
        for(int i = 0; i < m; i++ ) numPath[i][0] = 1;
        for( int j = 1; j < n; j++ ) numPath[0][j] = 1;
        
        for(int i = 1; i < m; i++ )
            for( int j = 1; j < n; j++ )
                numPath[i][j] = numPath[i-1][j] + numPath[i][j-1];
        return numPath[m-1][n-1];
    }
};