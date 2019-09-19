// 56 ms, faster than 97.74%

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if( m == 0 ) return false;
        int n = matrix[0].size();
        if( n == 0 ) return false;
        if( target < matrix[0][0] || target > matrix[m-1][n-1] ) return false;
        
        int row = 0, col = n-1; // 从右上角开始扫
        while( row <= m-1 && col >= 0 ){
            int cur = matrix[row][col];
            if( target == cur )
                return true;
            else if( target > cur )
                row++;
            else
                col--;
        }
        return false;
    }
};