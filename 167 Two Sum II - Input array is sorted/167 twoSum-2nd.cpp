// 8 ms, faster than 56.86% 

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int l = 0, r = numbers.size()-1;
        while(l < r){
            int sum = numbers[l] + numbers[r];
            if( sum == target ){
                res.push_back(l+1), res.push_back(r+1);
                break;
            }
            else if( sum > target ) r--;
            else l++;
        }
        return res;
    }
};