class Solution {
public:
    string reverseString(string s) {
        if(s.size() == 0)
            return s;
        else{
            int l = 0;
            int r = s.size() - 1;
            
            while(l < r){
                swap(s[l++],s[r--]);
            }
            if(l >= r)
                return s;
        }
    }
};