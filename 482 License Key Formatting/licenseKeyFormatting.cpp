// 10 ms
// Brutal-force: traverse from back to front
// But accumulate res by "res += " and return reversed res

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string res = "";
        int numberLeft = K;
        for( int i = S.size()-1 ; i >= 0; i-- ){
            char tmp = S[i];
            if( tmp != '-'){
                if( numberLeft == 0 ){
                    res += "-";
                    numberLeft = K;
                }
                if( tmp >= 'a' && tmp <= 'z') tmp = 'A'+ tmp-'a';
                res += tmp ;
                numberLeft--;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// 233 ms
// Brutal-force: traverse from back to front

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string res = "";
        int numberLeft = K;
        for( int i = S.size()-1 ; i >= 0; i-- ){
            if( S[i] != '-'){
                if( numberLeft == 0 ){
                    res = "-" + res;
                    numberLeft = K;
                }
                res = (char)toupper(S[i]) + res;
                numberLeft--;
            }
        }
        return res;
    }
};

// sample 6ms code
// when I run it, it is 13ms, not as fast as my optimized solution

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int total = 0;
        for (auto c : S)
        {
            if (c != '-')
                total ++;
        }
        
        if (total == 0)
            return "";
        int group = ceil(double(total) / K);
        int firstGroup = total - (group - 1) * K;
        string ans(group - 1 + total, ' ');
        int i = 0;
        int j = 0;
        int g = group;
        while (g --)
        {
            int num = (g == group - 1) ? firstGroup : K;
            while (num --)
            {
                while (S[j] == '-')
                {
                    j ++;
                }
                ans[i ++] = toupper(S[j ++]);                
            }
            if (g != 0) ans[i ++] = '-';
        }
        
        return ans;
    }
};
