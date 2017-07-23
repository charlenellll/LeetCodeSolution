class Solution {
public:
    // Determine whether current element is alphanumeric
    bool isAlphanumeric(const char c){
        if(c >= '0' && c <= '9')
            return true;
        else if(c >= 'a' && c <= 'z')
            return true;
        else if(c >= 'A' && c <= 'Z')
            return true;
        else
            return false;
    } 
    // Convert upper case to lower case
    char toLower(const char c){
        if(c >= 'A' && c <= 'Z')
            return c+32;
        else
            return c;
    }
    bool isPalindrome(string s) {
        if(s.size() == 0 || s.size() == 1) //If the string is not longer than 2
            return true;
        
        else{ //When the string is longer than 2
            int l = 0;
            int r = s.size() - 1;
            
            while(l < r){
                while(l < r && (!isAlphanumeric(s[l])))
                    l++;
                while(r > l && (!isAlphanumeric(s[r])))
                    r--;
                if(toLower(s[l]) != toLower(s[r]))
                    return false;
                else if(toLower(s[l]) == toLower(s[r])){
                    l++;
                    r--;
                }
            }
            if(l >= r)
                return true;
        }
    }
};