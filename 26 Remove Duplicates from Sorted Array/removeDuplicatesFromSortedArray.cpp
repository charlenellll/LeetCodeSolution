class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        
        if(nums.size() > 0){
            // If the array is in ascending order
            for(int i = 1; i < nums.size(); i++){
                if(nums[i] > nums[i-1]){
                    if(i != k)
                        nums[++k] = nums[i];  // No need to use swap
                    else //i==k
                        k++;
                }
            }
            return k+1;
        }
        else{
            return 0;
        }
    }
};