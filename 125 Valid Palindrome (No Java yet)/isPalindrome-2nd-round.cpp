// 8 ms, faster than 71.11% submissions
class Solution {
private:
    char toUpper(char c){
        if( c >= 'a' && c <= 'z')
            return c + 'A'-'a';
        else return c ;
    }
    bool isAlphaNumeric(char c){
        if( (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
            return true;
        else return false;
    }
public:
    bool isPalindrome(string s) {
        if( s.size() == 0 ) return true;
        int l = 0, r = s.size()-1;
        while( l < r ){
            while( !isAlphaNumeric(s[l] ) ) l++;
            while( !isAlphaNumeric( s[r]) ) r--;
            if( l >= r ) break;
            if( toUpper(s[l]) != toUpper(s[r]) ) return false;
            else l++, r--;
        }
        return true;
    }
};