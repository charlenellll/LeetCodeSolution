class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = -1, two = nums.size();
        
        for(int i = 0; i < two; ){ //There is one situation that i does not ++
            if(nums[i] == 1)
                i++;
            else if(nums[i] == 2){
                swap(nums[--two],nums[i]);      
            }else{ //nums[i] == 0
                assert( nums[i] == 0 ); //Make sure input is right
                swap(nums[++zero],nums[i++]);
            }
        }
    }
};