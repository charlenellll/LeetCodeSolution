class Solution {
private:
    int f(string s){
        int count[26] = {0};
        for(char c : s) count[c-'a']++;
        for(int i = 0; i < 26; i++)
            if( count[i] != 0 ) return count[i];
        return -1;
    }
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> res;
        unordered_map<int,int> fw;
        for(auto w : words){
            int cnt = f(w);
            fw[cnt]++;
        }
        for(auto q: queries){
            int q_cnt = f(q);
            int result = 0;
            for(auto record : fw )
                if( q_cnt < record.first )
                    result += record.second;
            res.push_back(result);
        }
        return res;
    }
};