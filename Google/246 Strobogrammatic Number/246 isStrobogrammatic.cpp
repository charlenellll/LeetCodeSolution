// O(N) Time, O(1) Space
// 0 ms, beats 100%

class Solution {
private:
    int isPair(char c){
        switch(c){
            case '0':
                return 0; break;
            case '1':
                return 1; break;
            case '6': 
                return 9; break;
            case '8':
                return 8; break;
            case '9':
                return 6; break;
            default:
                return -1; break;
        }
    }
public:
    bool isStrobogrammatic(string num) {
        int n = num.size();
        if( n == 0 ) return true;
        int p = 0, q = n-1;
        while( p <= q ){
            if( (num[q]-'0') != isPair(num[p]) ) return false;
            p++, q--;
        }
        return true;
    }
};