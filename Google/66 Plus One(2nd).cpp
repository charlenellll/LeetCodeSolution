// Straight-forward calculation
// 4 ms, 99.68%
// O(N) time, O(N) space

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int rest = 1;
        for(int i = digits.size() - 1; i >= 0; i--){
            int sum = digits[i] + rest;
            res.push_back( sum % 10 );
            rest = sum / 10;
        }
        if( rest != 0 ) res.push_back(rest);
        reverse(res.begin(), res.end());
        return res;
    }
};

// * A optimized solution: O(1) space
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int rest = 1;
        for(int i = digits.size()-1; i >= 0 ; i--){
            digits[i] = digits[i] + rest;
            if( digits[i] == 10 ){
                digits[i] = 0;
                rest = 1;
            }
            else rest = 0;
        }
        if( rest == 1 )
            digits.insert(digits.begin(), 1);
        return digits;
    }
};