// 80.5%
// Brutal force

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int res = 0;
        if( m == 0 ) return res;
        
        int n = grid[0].size();
        for(int i = 0; i < m; i++ )
            for(int j = 0; j < n; j++){
                if( grid[i][j] == 1 ){
                    res += 4;
                    if( i > 0 && grid[i-1][j] == 1 )
                        res --;
                    if( j > 0 && grid[i][j-1] == 1)
                        res --;
                    if( i < m-1 && grid[i+1][j] == 1)
                        res --;
                    if( j < n-1 && grid[i][j+1] == 1)
                        res --;
                }
            }
        return res;
    }
};