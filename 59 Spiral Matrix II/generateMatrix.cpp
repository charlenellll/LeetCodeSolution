class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if( n == 0 ) return vector<vector<int>>();
        vector<vector<int>> res(n, vector<int>(n, 0));
        int left = 0, right = n-1, top = 0, bot = n-1, x = 0, y = 0, dx = 1, dy = 0;
        for(int i = 1; i <= n*n; i++ ){
            res[x][y] = i;
            x += dy, y += dx;
            if( dx == 1 && y > right ) x++, y--, top++, dx = 0, dy = 1;
            else if( dy == 1 && x > bot ) x--, y--, right--, dx = -1, dy = 0;
            else if( dx == -1 && y < left ) x--, y++, bot--, dx = 0, dy = -1;
            else if( dy == -1 && x < top ) x++, y++, left++, dx = 1, dy = 0;
        }
        return res;
    }
};