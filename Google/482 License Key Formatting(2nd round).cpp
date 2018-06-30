// 优化后的简短版本：
// 11 ms
// beats 99%

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string res = "";
        int counter = 0;
        for( int i = S.size()-1; i >= 0; i-- ){
            char tmp = toupper(S[i]);
            if( (tmp >= 'A' && tmp <= 'Z') || (tmp >= '0' && tmp <= '9') ){
                if( counter == K ) {
                    res += '-';
                    counter = 0;
                }
                res += tmp;
                counter ++;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


// 12 ms
// beats 98.58%
// Brutal-force traverse from back to front

class Solution {
private:
    bool isAlphaNumeric(char c){
        if( (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            return true;
        return false;
    }
public:
    string licenseKeyFormatting(string S, int K) {
        if(S.size() == 0 ) return S;

        string res = "";
        int counter = 0;
        for( int i = S.size()-1; i >= 0; i-- ){
            if( counter == K ) {
                res += '-';
                counter = 0;
            }

            S[i] = toupper(S[i]);
            if( !isAlphaNumeric(S[i]) ) // 这个应当放到”加dash“代码之外，因为理论上当输入字符是横线时我们不做任何操作，要把它排除所有操作之外
                continue;
            else{
                res += S[i];
                counter ++;
            }
        }

        while( res[res.size() - 1] == '-')  // 这里会有"--a-a-a-a--"用例输出为"AA-AA的情况"，是由于前面判断字符是否是alphanumeric位置不对，见上！
            res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};