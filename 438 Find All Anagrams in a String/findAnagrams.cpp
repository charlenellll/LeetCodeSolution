class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        //It is easier to use vectors to compare frequency of characters
        vector<int> freqInP(26,0);
        vector<int> freqInS(26,0);
        
        int l = 0, r = -1;
        vector<int> index;
        
        for(int i = 0; i < p.size(); i++)
            freqInP[p[i]%97] ++;
        
        // Keep the size of sliding window to p.size()
        while(l < s.size()){
            
            if(r-l+1 <= p.size() && r+1 < s.size())
                freqInS[s[++r]%97] ++;
            else
                freqInS[s[l++]%97] --;

            //Determine if s[l...r] is an anagram of p
            if(freqInS == freqInP)
                index.push_back(l); //This way can avoid compilation failure
        }
        return index;
    }
};