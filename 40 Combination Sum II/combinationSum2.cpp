class Solution {
private:
    vector<vector<int>> result;
    void doCombination( vector<int>& candidates, int target, int index, vector<int> res ){
        
        if( target == 0 ){
            result.push_back(res);
            return;
        }
        for( int i = index; i < candidates.size() && candidates[i] <= target; i++){
    
            //when i is not the current index and candiates[i-1] has been used, skip its duplicates
            if( i > index && candidates[i] == candidates[i-1] ) continue;
            res.push_back( candidates[i] );
            doCombination( candidates, target-candidates[i], i+1, res);
            res.pop_back();
        }
        return;
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort( candidates.begin(), candidates.end() );
        
        result.clear();
        vector<int> res;
        doCombination( candidates, target, 0, res );
        
        return result;
    }
};