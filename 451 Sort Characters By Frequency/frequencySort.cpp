//112 ms, faster than 94.29% of C++ online submissions

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> record;
        for(int i = 0; i < s.size(); i++) record[s[i]]++;
        map<int, vector<char>, greater<int>> freq;
        for(auto iter: record)
            freq[iter.second].push_back(iter.first);
        string res = "";
        for(auto iter: freq)
            for(auto c: iter.second)
                for(int i = 0; i < iter.first; i++)
                    res += c;
        return res;
    }
};