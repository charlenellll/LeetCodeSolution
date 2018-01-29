// Solution 2
// 2 ms
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if( matrix.empty() ) return vector<int>();
        // number of rows       number of columns
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res;
        int left = 0, right = n-1, top = 0, bot = m-1, x = 0, y = 0, dx = 1, dy = 0;
        for( int i = 0; i < m*n; i++ ){
            res.push_back( matrix[x][y] );
            x += dy, y += dx;
            if( dx == 1 && y > right ) dx = 0, dy = 1, top++, y--, x++;
            else if( dy == 1 && x > bot ) dx = -1, dy = 0, right--, x--, y--;
            else if( dx == -1 && y < left ) dx = 0, dy = -1, bot--, y++, x--;
            else if( dy == -1 && x < top ) dx = 1, dy = 0, left++, x++, y++;
        }
        return res;
    }
};


// Solution 1
// 4 ms

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if( matrix.empty() ) return vector<int>();
        // max index of rows       max index of columns
        int m = matrix.size() - 1, n = matrix[0].size() - 1;
        vector<int> res;
        // x and y represent the upmost row_number and leftmost column_number in each spiral circle
        for( int x = 0, y = 0; x <= m && y <= n; x++, y++){
            for( int j = y; j <= n; j++ ) // works when x = m
                res.push_back( matrix[x][j]);
            for( int i = x + 1; i <= m; i++ ) // works when y == n
                res.push_back( matrix[i][n] );
            for( int j = n - 1; j >= y && x != m; j-- ) // if x == m, it has already been traversed in the first loop
                res.push_back( matrix[m][j] );
            for( int i = m - 1; i > x && y != n; i-- ) // if y == n, it has already been traversed in the second loop
                res.push_back( matrix[i][y] );
            m--;
            n--;
        }
        return res;
    }
};