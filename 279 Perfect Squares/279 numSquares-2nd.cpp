// 2. Graph - BFS
// Optimization 2: return result when inside the for loop, 
// so we don't have to store the result we desire along with all other possibilities into queue, and pick it out in the next loop
// 24 ms, faster than 87.89%
class Solution {
public:
    int numSquares(int n) {// BFS 
        if( n <= 1 ) return n;
        vector<bool> visited(n+1, false); // visited[i] means if number i is visited in the graph
        queue<pair<int, int>> q;// record number with the steps to get to it
        q.push( make_pair(n, 0) );
        while( !q.empty() ){
            int num = q.front().first;
            int step = q.front().second;
            q.pop();
            for(int i = 0; i*i <= num; i++ ){
                int curNum = num-i*i;
                if( curNum == 0 ) return step+1; // when the first num=0 occurs, its "steps" is the result
                if( visited[curNum] == false ){
                    q.push(make_pair(curNum, step + 1));
                    visited[curNum] = true;
                }
            }
        }
        return -1; // no such solution, though not possible
    }
};

// Optimization 1: do not visit the same num! so we need to record visited num
// 132 ms, faster than 37.98%
// Not TLE, but still slow
class Solution {
public:
    int numSquares(int n) {// BFS 
        if( n <= 1 ) return n;
        vector<bool> visited(n+1, false); // visited[i] means if number i is visited in the graph
        queue<pair<int, int>> q;// record number with the steps to get to it
        q.push( make_pair(n, 0) );
        while( !q.empty() ){
            int num = q.front().first;
            int step = q.front().second;
            q.pop();
            // when the first number=0 occurs, its "steps" is the result
            if( num == 0 ) return step;
            for(int i = 0; i*i <= num; i++ )
                if( visited[num-i*i] == false ){
                    q.push(make_pair(num - i*i, step + 1));
                    visited[num-i*i] = true;
                }
        }
        return -1; // no such solution, though not possible
    }
};

// TLE on test case 7168! we need optimization!
// Reason: visit the same num nultiple times from different path in the graph
class Solution {
public:
    int numSquares(int n) {// BFS 
        if( n <= 1 ) return n;
        queue<pair<int, int>> q;// record number with the steps to get to it
        q.push( make_pair(n, 0) );
        while( !q.empty() ){
            int num = q.front().first;
            int step = q.front().second;
            q.pop();
            // when the first number=0 occurs, its "steps" is the result
            if( num == 0 ) return step;
            for(int i = 0; i*i <= num; i++ )
                q.push(make_pair(num - i*i, step + 1));
        }
        return -1; // no such solution, though not possible
    }
};

// 1. DP O(N^2) time O(N) space, 注意这两种方法的时间差别
// 84 ms, faster than 76.14%
class Solution {
public:
    int numSquares(int n) {// memo[i] represents the least number of perfect square numbers that add up to i
        if( n <= 1 ) return n;
        vector<int> memo(n+1, 0);
        memo[0] = 0;
        memo[1] = 1;
        for(int i = 2; i <= n; i++ ){
            int minNum = INT_MAX;
            for(int j = 1; j * j <= i; j++)
                minNum = min(minNum, 1 + memo[i-j*j]);
            memo[i] = minNum;
        }
        return memo[n];
    }
};

// 反复对vector中的一个元素赋值没有直接用一个int快！
// 104 ms, faster than 63.15%
class Solution {
public:
    int numSquares(int n) {// memo[i] represents the least number of perfect square numbers that add up to i
        if( n <= 1 ) return n;
        vector<int> memo(n+1, INT_MAX);
        memo[0] = 0;
        memo[1] = 1;
        for(int i = 2; i <= n; i++ )
            for(int j = 1; j * j <= i; j++)
                memo[i] = min(memo[i], 1 + memo[i-j*j]);
        return memo[n];
    }
};

