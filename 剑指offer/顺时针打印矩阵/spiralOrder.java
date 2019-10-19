// 二维数组代替方向版
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        // 返回值
        List<Integer> res = new ArrayList<>();
        
        int m = matrix.length;
        if( m == 0 )
            return res;
        
        int n = matrix[0].length;
        if( n == 0 ) 
            return res;
        
        // 定义元素的访问状态
        boolean[][] visited = new boolean[m][n];
        
        // 定义遍历的元素索引
        int r = 0;
        int c = 0;
        // 定义方向（顺时针方向）
        int[][] direction = new int[][]{
                {0, 1},
                {1, 0},
                {0, -1},
                {-1, 0}
        };
        int di = 0;  // 当前方向索引
        
        // 遍历元素
        for( int i = 0; i < m * n ; i++ ) {
            // 添加元素
            res.add(matrix[r][c]);
            visited[r][c] = true;
            
            // 更新索引
            int nr = r + direction[di][0];
            int nc = c + direction[di][1];
            
            // 判断索引合法性
            if( nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc] ) {
                r = nr;
                c = nc;
            } else {
                // 顺时针递推到下一个方向
                di = ++di % 4;
                r = r + direction[di][0];
                c = c + direction[di][1];
            }
        }
        
        return res;
    }
    
}