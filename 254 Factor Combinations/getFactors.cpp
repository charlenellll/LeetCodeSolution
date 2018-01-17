// 2ms

class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        
        vector<vector<int>> result;
        if( n <= 1 ) return result;
        vector<int> res;
        getFac(n, 2, res, result);
        return result;
    }
                        // index marks the start index of i, aka the number i could start to try
    void getFac(int n, int index, vector<int> res, vector<vector<int>> &result){
        for( int i = index; i <= sqrt(n); i++ )
            if( n % i == 0 ){
                res.push_back(i), res.push_back(n/i);
                result.push_back(res);
                res.pop_back();
                getFac(n/i, i, res, result);
                res.pop_back();
            }
        }
};