// 8ms
// beats 99.97%

class Solution {
private:
	// stores the elements in the diagonal
	vector<int> diag;
public:
	bool isToeplitzMatrix(vector<vector<int>>& matrix){
		int m = matrix.size();
		if( m == 0 ) return true;
		int n = matrix[0].size();
		if( n == 0 ) return true;

		diag = vector<int>(m+n-1, -1);
		int complement = n-1;
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++){
				if( diag[i-j+complement] == -1 )
					diag[i-j+complement] = matrix[i][j];
				else{
					if( diag[i-j+complement] != matrix[i][j])
						return false;
				}
			}
		return true;
	}
};