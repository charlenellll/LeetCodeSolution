// 324 ms

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        
        if( A.size() == 0 || B.size() == 0 )
            return vector<vector<int>>();
        
        vector<vector<int>> AB( A.size(), vector<int>(B[0].size(), 0) );
        for( int i = 0; i < A.size(); i++ )
            for( int j = 0; j < B[0].size(); j++ )
                for( int k = 0; k < A[0].size(); k++ )
                    // It is a sparse matrix, this judgement is important!
                    if( A[i][k] != 0 && B[k][j] != 0 ){
                        AB[i][j] += A[i][k] * B[k][j];
            }
        return AB;
    }
}

// After optimization

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        
        int m = A.size();
        int nA = ( m == 0 ) ? 0 : A[0].size();
        int n = ( B.size() == 0 ) ? 0 : B[0].size();
        
        if( m == 0 || nA == 0 || n == 0 )
            return vector<vector<int>>();
        
        vector<vector<int>> AB(m, vector<int>(n, 0));
        for( int i = 0; i < m; i++ )
            for( int k = 0; k < nA; k++ )
                if( A[i][k] != 0 )
                    for( int j = 0; j < n; j++ )
                        if( B[k][j] != 0 )
                            AB[i][j] += A[i][k] * B[k][j];
        
        return AB;
    }
};