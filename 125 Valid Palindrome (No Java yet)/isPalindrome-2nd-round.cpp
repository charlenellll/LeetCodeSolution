// 3rd round - 1 
// 8 ms, faster than 84.13%
class Solution {
private:
    bool isAlphaNumeric(char c){
        if( (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') ) return true;
        else return false;
    }
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size()-1;
        while( l < r ){
            while( !isAlphaNumeric(tolower(s[l])) && l < r ) l++;
            while( !isAlphaNumeric(tolower(s[r])) && l < r ) r--;
            if( tolower(s[l]) == tolower(s[r]) ) l++, r--;
            else return false;
        }
        return true;
    }
};

// 3rd round - 2
// Use c++ isalnum() function, the code is more concise but slower!!
// 12 ms, faster than 39.35% 

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size()-1;
        while( l < r ){
            while( !isalnum(s[l]) && l < r ) l++;
            while( !isalnum(s[r]) && l < r ) r--;
            if( tolower(s[l]) == tolower(s[r]) ) l++, r--;
            else return false;
        }
        return true;
    }
};

// 2nd round
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