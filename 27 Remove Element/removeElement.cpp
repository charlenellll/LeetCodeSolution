class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] != val)
                if(i != k){
                    swap(nums[i], nums[k++]);
                }
                else{
                    k++;
                }
        }
        return k;
    }
};