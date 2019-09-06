// 2. optimizarion: use vectors to replace maps, because strings consists of lowercase English letters 
// 40 ms, faster than 41.55%
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> recordS(26,0), recordP(26,0), res;
        for(int i = 0; i < p.size(); i++ ) recordP[p[i]-'a']++;
        int l = 0, r = -1;
        while( l < s.size() ){ //the size of window should be exact the size of p
            if( r+1 < s.size() && r-l+1 <= p.size() ) 
                recordS[s[++r]-'a']++;
            else
                recordS[s[l++]-'a']--;
            if( recordS == recordP ) 
                res.push_back(l);
        }
        return res;
    }
};

// 1. A clumsy solution, not suggested
// 188 ms, faster than 10.05%

class Solution {
private:
    bool isContain(unordered_map<int,int>& s, unordered_map<int,int>& p){
        for(auto item: p){
            if( s.find(item.first) == s.end() ) return false;
            else if( s[item.first] < item.second ) return false;
        }
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<int, int> recordS;
        unordered_map<int, int> recordP;
        vector<int> res;
        for(int i = 0; i < p.size(); i++ ) recordP[p[i]]++;
        int l = 0, r = -1;
        while( l < s.size() ){
            if( r+1 < s.size() && !isContain(recordS,recordP) ) recordS[s[++r]]++;
            else{
                if( recordS == recordP ) res.push_back(l);
                recordS[s[l]]--;
                if( recordS[s[l]] == 0 ) recordS.erase(s[l]); // because I use recordS==recordP to judge the condition, this is crucial!
                l++;
            }
        }
        return res;
    }
};