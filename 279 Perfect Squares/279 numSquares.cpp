// Solution 2: BFS - shortest path in the graph（28 ms, faster than 85.99% ）
class Solution {
public:
    int numSquares(int n) {
        queue<pair<int,int>> q;//第几个数字 经过几段路径到了这个数字（最后求(0,step)）
        q.push(make_pair(n, 0));
        vector<bool> visited(n+1, false);
        while( !q.empty() ){
            int num = q.front().first;
            int step = q.front().second;
            q.pop();
            for( int k = 1; ; k++ ){
                int a = num - k*k;
                if( a < 0 ) break;
                if( a == 0 ) return step+1;
                if( !visited[a] ){
                    q.push(make_pair(a, step+1));
                    visited[a] = true;
                }
            }
        }
        return -1;
    }
};

// Solution 1: DP（80 ms, faster than 76.63%）
class Solution {
public:
    int numSquares(int n) { //num[i]表示加起来为i的perfect square的最小个数
        // num[i] = min(1 + num[i-k*k]), k*k为perfect square ( 1 <= k*k <= i )
        vector<int> num(n+1, 0);
        for(int i = 1; i <= n; i++ ){
            int minNum = INT_MAX;
            for(int k = 1; k*k <= i; k++)
                minNum = min( 1 + num[i-k*k], minNum); //不能直接用num[i]因为如此使用需初始为INT_MAX但1+num[i-k*k]可能溢出
            num[i] = minNum;
        }
        return num[n];
    }
};