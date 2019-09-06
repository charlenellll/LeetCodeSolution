// 3rd round
// 8 ms, faster than 93.00%
class Solution {
private:
    bool isVowel(char c){
        if( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        else return false;
    }
public:
    string reverseVowels(string s) {
        int l = 0, r = s.size()-1;
        while( l < r ){
            while( l < r && !isVowel(tolower(s[l])) ) l++;
            while( l < r && !isVowel(tolower(s[r])) ) r--;
            swap(s[l++], s[r--]);
        }
        return s;
    }
};

// 8ms
// beats 99.1%

class Solution {
private:
    bool isVowel(char c){
        char upperC = toupper(c);
        if( upperC == 'A' or upperC == 'E' or upperC == 'I' or upperC == 'O' or upperC == 'U') return true;
        return false;
    }
public:
    string reverseVowels(string s) {
        int p = 0, q = s.size()-1;
        
        while( p < q ){
            while( p < q && !isVowel(s[p]) ) p++;
            while( p < q && !isVowel(s[q]) ) q--;
            swap(s[p++], s[q--]);
        }
        return s;
    }
};