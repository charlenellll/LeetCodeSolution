class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        // O(NlogN)
        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());
        
        int si = 0, gi = 0;
        int res = 0;
        while(si < s.size() && gi < g.size()){
            if(s[si] >= g[gi]){
                res++;
                si++;
                gi++;
            }
            else
                gi++;
        }
        
        return res;
    }
};