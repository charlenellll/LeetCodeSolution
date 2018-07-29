// O(max(m,n)) time, O(1) space
// 4ms, beats 99.32%

class Solution {
public:
    string addStrings(string num1, string num2) {
        string res = "";
        int m = num1.length() - 1, n = num2.length() - 1;
        int rest = 0;
        for(int i = 0; i <= max(m, n); i++){
            int sum = 0;
            if( i <= m && i <= n ) sum = (num1[m-i]-'0') + (num2[n-i] - '0') + rest;
            if( i > m ) sum = num2[n-i]-'0' + rest;
            if( i > n ) sum = num1[m-i]-'0' + rest;
            rest = sum / 10;
            sum = sum % 10;
            res += '0'+sum;
        }
        if( rest != 0 ) res += '0'+rest;
        reverse(res.begin(), res.end());
        return res;
    }
};