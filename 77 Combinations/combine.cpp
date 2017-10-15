class Solution {
private:
    vector<vector<int>> res;
    vector<bool> used;
    // To compute C(n,k), put the unfinished combinations we found into c, and search for new element from "start" index
    void generateCombination(int n, int k, int start, vector<int> &c){
        
        if( c.size() == k ){
            res.push_back(c);
            return;
        }
        
        for(int i = start; i <= n; i++){
            c.push_back(i);
            // Think thoroughly why I made mistakes
            // why I need to use (i+1) instead of (start+1) here
            generateCombination(n, k, i+1 ,c);
            // After the recursion I need to backtracking(pop out) the element I just pushed in
            // so that I can add the next element to the sequence
            c.pop_back();
        }
        return;
    }
    
public:
    vector<vector<int>> combine(int n, int k) {
        
        if( n <= 0 || k <=0 || k > n)
            return res;
        
        vector<int> c;
        generateCombination(n,k,1,c);
        
        return res;
    }
};