// Solution 2: sort() the strings and record them just in one hash table
// 32 ms, faster than 96.99%
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        if( strs.size() == 0 ) return res;
        unordered_map<string, vector<string>> anagrams;
        for(int i = 0; i < strs.size(); i++ ){
            string curStr = strs[i];
            sort( curStr.begin(), curStr.end() );
            anagrams[curStr].push_back(strs[i]);
        }
        for(auto item: anagrams)
            res.push_back(item.second);
        return res;
    }
};

// Solution 1 does not work no matter optimized or not: ---------

// Optimization: use vector to replace hash maps since strs only contains lower case letters
// still TLE

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        vector<int> grouped(strs.size(), 0); // index of grouped elements
        for(int i = 0; i < strs.size(); i++ ){
            if( grouped[i] == 1 ) continue;
            vector<string> curRes;
            vector<int> recordA(26,0);
            for(int k = 0; k < strs[i].size(); k++ ) recordA[strs[i][k]-'a']++;
            for(int j = i+1; j < strs.size(); j++ ){
                if( grouped[j] == 1 || strs[i].size() != strs[j].size() ) continue;
                vector<int> recordB(26,0);
                for(int k = 0; k < strs[j].size(); k++ ) recordB[strs[j][k]-'a']++;
                if( recordA == recordB ){
                    curRes.push_back(strs[j]);
                    grouped[j] = 1;
                }
            }
            curRes.push_back(strs[i]);
            grouped[i] = 1;
            res.push_back(curRes);
        }
        return res;
    }
};

// Solution 1: for each word, use unordered_map to record freq of each characters
// This method consumes too much time, TLE when test case contains too many strs
// TLE, 100/101 test cases passed

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_set<int> grouped; // index of grouped elements
        for(int i = 0; i < strs.size(); i++ ){
            vector<string> curRes;
            unordered_map<char,int> recordA;
            for(int k = 0; k < strs[i].size(); k++ ) recordA[strs[i][k]]++;
            if( grouped.find(i) != grouped.end() )
                    continue;
            for(int j = i+1; j < strs.size(); j++ ){
                if( grouped.find(j) != grouped.end() || strs[i].size() != strs[j].size() )
                    continue;
                unordered_map<char,int> recordB;
                for(int k = 0; k < strs[j].size(); k++ ) recordB[strs[j][k]]++;
                if( recordA == recordB ){
                    curRes.push_back(strs[j]);
                    grouped.insert(j);
                }
            }
            curRes.push_back(strs[i]);
            grouped.insert(i);
            res.push_back(curRes);
        }
        return res;
    }
};