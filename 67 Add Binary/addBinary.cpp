class Solution {
public:
    string addBinary(string a, string b) {
        
        string res = "";
        
        if( a.size() == 0 && b.size() ==0 ) return res;
        
        int pa = a.size() - 1;
        int pb = b.size() - 1;
        int rest = 0;
        
        while( pa >= 0 || pb >= 0 || rest != 0 ){
            int sum = 0;
            if( pa >= 0 && pb >= 0 ) sum = (a[pa--]-'0') + (b[pb--]-'0') + rest ;
            else if( pa >= 0 ) sum = (a[pa--]-'0') + rest;
            else if(pb >= 0 )sum = (b[pb--]-'0') + rest;
            else sum = rest;
            
            rest = sum / 2;
            sum = sum % 2;
            res = to_string(sum) + res;
        }
        
        return res;
    }
};