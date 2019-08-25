// 8 ms, faster than 99.19% of C++ online submissions 

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string res = "";
        int count = 0;
        for( int i = S.size()-1; i >= 0 ; i-- ){
            if( S[i] != '-' ){ 
                res += toupper(S[i]);
                count ++;
                if( count % K == 0 ) res += "-";
            }
        }
        if( res[res.size()-1] == '-') res = res.substr(0, res.size()-1);
        reverse(res.begin(), res.end());
        return res;
    }
};