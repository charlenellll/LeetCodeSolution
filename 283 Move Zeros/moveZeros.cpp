class Solution {
public:
    void moveZeroes(vector<int>& nums) {
		int k = 0; //In nums,[0,k) places are non-zero elements
		
		for(int i = 0; i<nums.size(); i++){
			if(nums[i])
				if(i!=k)
					swap(nums[i], nums[k++]);
				else //i = k
					k++;
		}  
    }
};