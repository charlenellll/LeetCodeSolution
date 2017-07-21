public class Solution {
    public int removeDuplicates(int[] nums) {
        int k = 0;
        
        if(nums.length == 0){ // If the array is empty
            return 0;
        }else{ // If it is not empty
            for(int i = 1; i<nums.length; i++){
                if(nums[i] > nums[i-1]){
                    if(i != k)
                        nums[++k] = nums[i];
                    else
                        k++;
                }       
            }
            return k+1;
        }
    }
}