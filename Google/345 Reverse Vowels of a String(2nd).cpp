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