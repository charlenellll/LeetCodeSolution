class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int l = 0, r = numbers.size() - 1;
        while(l < r){
            if(numbers[l] + numbers[r] == target){
                int res[2] = {l+1, r+1};
                return vector<int>(res, res+2);
            }else if(numbers[l] + numbers[r] < target)
                l++;
            else
                r--;
        }
        throw invalid_argument("The input has no solution.");
    }
};