// Solution 2: Binary Search, O(logM)+O(logN)



// Solution 1: Straight forward, O(M)+O(N)
// 8 ms, faster than 93.83% 

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if( m == 0 ) return false;
        int n = matrix[0].size();
        if( n == 0 ) return false;
        if( target < matrix[0][0] || target > matrix[m-1][n-1] ) return false;
        
        int row = 0, col = 0;
        while( row <= m-1 && col <= n-1 ){
            int cur = matrix[row][col];
            if( target == cur ) return true;
            else if( target > cur ){
                if( target > matrix[row][n-1] ) row++;
                else col++;
            }
            else //如果小的话，说明之前所在的数比target小，当前所在的数比target大，于是matrix中不存在target
                return false;
        }
        return false;
    }
};