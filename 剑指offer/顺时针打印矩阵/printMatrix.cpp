// 两个方法都是 O(N) time O(1) space
// 二维数组控制方向版 22 lines:
// 运行时间：4ms 占用内存：476k
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res;//注意col的起点是-1因为按照循环中的定义，当前还没有遍历任何元素
        int row = 0, col = -1, cnt = 0, m = matrix.size(), n = (n==0)? 0 : matrix[0].size(), direction = 0; // 0-右，1-下，2-左，3-上
        if( m == 0 || n == 0 ) return res;
        int d[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        while( cnt < m*n ){//每次循环进行一个方向的遍历
            int dIndex = direction % 4;//确定方向
            int newR = row + d[dIndex][0], newC = col + d[dIndex][1]; //不用计算起始点因为有方向控制
            while( newR >= 0 && newR <= m-1 && newC >= 0 && newC <= n-1 && matrix[newR][newC] != INT_MIN){ //不用自己计算boundary，直接用该元素是否被遍历过（INT_MIN）进行判别
                res.push_back( matrix[newR][newC]);
                matrix[newR][newC] = INT_MIN;
                cnt++;
                newR = d[dIndex][0] + newR, newC = d[dIndex][1] + newC;
            }
            row = newR - d[dIndex][0], col = newC - d[dIndex][1];
            direction++;
        }
        return res;
    }
};

// 直观版 57 lines：
// 运行时间：3ms 占用内存：472k
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res;
        int direction = 0; // 0-右，1-下，2-左，3-上
        int row = 0, col = 0, cnt = 0;
        int n = matrix.size(), m = (n==0)? 0 : matrix[0].size();
        if( m == 0 || n == 0 ) return res;
        while( cnt < m*n ){
            int i;
            switch( direction % 4 ){
                case 0:{
                    i = direction/4;
                    for( ; i < m && matrix[row][i] != INT_MIN; i++){
                        res.push_back( matrix[row][i] );
                        matrix[row][i] = INT_MIN;
                        cnt++;
                    }
                    col = i-1;
                    break;
                }
                case 1:{
                    i = direction/4 + 1;
                    for( ; i < n && matrix[i][col] != INT_MIN; i++ ){
                        res.push_back( matrix[i][col] );
                        matrix[i][col] = INT_MIN;
                        cnt++;
                    }
                    row = i-1;
                    break;
                }
                case 2:{
                    i = m-1 - direction/4 -1;
                    for( ; i >= 0 && matrix[row][i] != INT_MIN; i--){
                        res.push_back( matrix[row][i] );
                        matrix[row][i] = INT_MIN;
                        cnt++;
                    }
                    col = i+1;
                    break;
                }
                case 3:{
                    i = n-1 - direction/4 - 1;
                    for( ; i >= 0 && matrix[i][col] != INT_MIN; i--){
                        res.push_back( matrix[i][col] );
                        matrix[i][col]  = INT_MIN;
                        cnt++;
                    }
                    row = i+1;
                    break;
                }
            }
            direction++;
        }
        return res;
    }
};