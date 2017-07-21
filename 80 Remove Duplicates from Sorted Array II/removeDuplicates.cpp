class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        int count = 1; // The count of duplicates, since i starts from 1, count should also starts from 1
        
        if(nums.size() == 0){ //If the array is empty
            return 0;
        }else{ // If the array is not empty
            for(int i = 1; i < nums.size(); i++){
                if(nums[i] > nums[i-1] ){
                    count = 1;
                    k++;
                    if(i != k){
                        nums[k] = nums[i];
                    }
                }else if(nums[i] == nums[i-1] && count==1){
                    count = 2;
                    k++;
                    if(i != k){
                        nums[k] = nums[i];
                    }
                }
            }
            return k+1;
        }
    }
};