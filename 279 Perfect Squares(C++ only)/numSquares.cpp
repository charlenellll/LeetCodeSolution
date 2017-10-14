class Solution {
public:
    int numSquares(int n) {
        
        assert( n > 0 );
        
        queue< pair<int,int> > q;
        q.push( make_pair(n, 0) );
        
        // To avoid inserting same number into the queue, which
        vector<bool> visited(n+1, false); 
        visited[n] = true;
        
        while( !q.empty() ){
            int num = q.front().first;
            int step = q.front().second;
            q.pop();
            
            // if( num == 0 )
            //     return step;
            
            // for( int i = 1; num-i*i >= 0; i++ )
            //     if( !visited[num-i*i] ){
            //         q.push( make_pair(num-i*i, step + 1) );
            //         visited[num-i*i] = true;
            //     }
            
            for( int i = 1; ; i++ ){
                int a = num-i*i; // Reduce redundant calculation than the code above
                if( a < 0 )
                    break;
                if( a == 0 )
                    return step + 1;
                if( !visited[num-i*i] ){
                    q.push( make_pair(a, step + 1) );
                    visited[a] = true;
                }
            }
        }
        throw invalid_argument("No Solution.");
    }
};