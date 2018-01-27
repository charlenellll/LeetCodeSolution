// 4ms

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