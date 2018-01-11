class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        
        int m = A.size(), nA = A[0].size(), n = B[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        
        for (int i=0; i<m; ++i) {
            for (int j=0; j<nA; ++j) {
                // Do not straight into the loop! start the loop when it is not 0!
                if (A[i][j] != 0) {
                    for (int k=0; k<n; ++k) {
                        if (B[j][k] != 0) {
                            res[i][k] += A[i][j] * B[j][k];
                        }
                    }
                }
            }
        }
        return res;
    }
};