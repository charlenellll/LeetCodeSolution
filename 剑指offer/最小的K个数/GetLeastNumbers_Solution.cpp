// S2可优化为 O(Nlog(min(k, n-k))) 不过代码较为繁琐，会多一段
// S2: 堆 O(Nlogk) time O(k) space
// 运行时间：3ms 占用内存：480k
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        int n = input.size();
        if( k == n ) return input;
        vector<int> res;
        if( k > n ) return res;
        
        priority_queue<int> pq;//默认为最大堆
        for( int i = 0; i < n; i++ ){
            pq.push( input[i] );
            if( pq.size() > k )
                pq.pop();
        }
        while( !pq.empty() ){
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};

// S1: 最直接：排序 O(NlogN) time O(1) space
// 运行时间：4ms 占用内存：492k
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if( k == input.size() ) return input;
        vector<int> res;
        if( k > input.size() ) return res; //test case定义的逻辑是若k过大则没有意义
        sort( input.begin(), input.end());
        for(int i = 0; i < k; i++ )
            res.push_back( input[i] );
        return res;
    }
};