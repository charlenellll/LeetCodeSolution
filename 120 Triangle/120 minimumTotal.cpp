// 4 ms, faster than 95.95%
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if( n == 0 || (n != 0 && triangle[0].size() == 0 )) return 0;
        vector<int> curSum(n, -1);
        for( int col = 0; col < n; col++ )
            curSum[col] = triangle[n-1][col];
        for( int row = n-2; row >= 0; row-- )
            for( int col = 0; col <= row; col ++ )
                curSum[col] = triangle[row][col] + min(curSum[col], curSum[col+1]);
        return curSum[0];
    }
};