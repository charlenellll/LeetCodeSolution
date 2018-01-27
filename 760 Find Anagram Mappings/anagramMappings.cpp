// 6ms

class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        vector<int> res;
        unordered_map<int,int> Bpos;
        for( int i = 0; i < B.size(); i++ )
            Bpos[B[i]] = i;
        for( int i = 0; i < A.size(); i++ )
            res.push_back( Bpos[A[i]] );
        return res;
    }
};