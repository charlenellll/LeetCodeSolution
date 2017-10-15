class Solution {
private:
    vector<vector<int>> res;
    vector<bool> used;
    void generateCombination(int n, int k, int start, vector<int> &c){
        
        if( c.size() == k ){
            res.push_back(c);
            return;
        }
        // There's k-c.size() vacancies left, so the slot [i..n] has to have at least k-c.size() elements
        for(int i = start; i <= n-(k-c.size())+1; i++){
            c.push_back(i);
            generateCombination(n, k, i+1 ,c);
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

// This code's runtime beats 98.63% cpp submissions