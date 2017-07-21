public class Solution {
    public int removeDuplicates(int[] nums) {
        int k = 0;
        int count = 1;
        
        if(nums.length == 0){
            return 0;
        }else{
            for(int i = 1; i < nums.length; i++){
                if(nums[i] > nums[i-1]){
                    count = 1;
                    k++;
                    if(i != k)
                        nums[k] = nums[i];
                }else if(nums[i] == nums[i-1] && count == 1){
                    count = 2;
                    k++;
                    if(i != k)
                        nums[k] = nums[i];                    
                }
            }
            return k+1;
        }
            
    }
}