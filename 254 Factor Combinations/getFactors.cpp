// 2ms

class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        
        vector<vector<int>> result;
        if( n <= 1 ) return result;
        vector<int> res;
        // notice that for the res I can use either copy method or & reference, it is small so no harm not using &
        // but for result we should use reference
        getFac(n, 2, res, result);
        return result;
    }
                        // index marks the start index of i, aka the number i could start to try
    void getFac(int n, int index, vector<int> &res, vector<vector<int>> &result){
        for( int i = index; i <= sqrt(n); i++ )
            if( n % i == 0 ){
                res.push_back(i), res.push_back(n/i);
                result.push_back(res);
                res.pop_back();
                getFac(n/i, i, res, result);
                // remember to delete the previous divisor during backtracking
                res.pop_back();
            }
        }
};


// 0ms sample code
class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                vector<int> tmp = {i, n / i};
                res.push_back(tmp);
                helper(tmp, res);
            }
        }
        
        return res;
    }
    
    void helper(vector<int>& cur, vector<vector<int>>& res) {
        int back = cur.back();
        cur.pop_back();
        
        for (int i = 2; i * i <= back; ++i) {
            if (back % i == 0 && i >= cur.back()) {
                cur.push_back(i);
                cur.push_back(back / i);
                res.push_back(cur);
                helper(cur, res);
                cur.pop_back();
                cur.pop_back();
            }
        }
        
        cur.push_back(back);
    }
};

// another version
class Solution {
public:
    void helper(vector<vector<int>>& res, vector<int>& comb, int fac, int n){
        for(int i = fac; i<=sqrt(n); ++i){
            if(!(n%i)){
                vector<int> tmp = comb;
                tmp.push_back(i);//push current factor
                helper(res, tmp, i, n/i);//find all other factor smaller than sqrt(n/i);
                tmp.push_back(n/i);//add n/i(the largest factor under current combination.
                res.push_back(tmp);
            }
        }
    }
    vector<vector<int>> getFactors(int n){
        vector<vector<int>> res;
        vector<int> comb;
        helper(res, comb, 2, n);
        return res;
    }
};