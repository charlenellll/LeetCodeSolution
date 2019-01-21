// 20 ms, beats 99.78% c++ submissions

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        if( strs.size() == 0 ) return res;
        unordered_map<string, vector<string>> record;
        for(int i = 0; i < strs.size(); i++ ){
            string curStr = strs[i];
            sort(curStr.begin(), curStr.end());
            record[curStr].push_back(strs[i]);
        }
        for(auto iter: record)
            res.push_back(iter.second);
        return res;
    }
};