// O(N) Time, O(N) Space
// 0 ms, beats 100%

class Solution {
private:
    unordered_map<char,int> record;
public:
    bool canPermutePalindrome(string s) {
        int n = s.size();
        if( n == 0 ) return true;

        for(int i = 0; i < n; i++){
            record[s[i]]++;
        }
        int cntOdd = 0;
        for( auto iter: record){
            if( iter.second % 2 != 0 ) cntOdd ++;
        }
        if( n % 2 == 0 && cntOdd == 0 ) return true;
        else if( n % 2 == 1 && cntOdd == 1 ) return true;
        else return false;
    }
};