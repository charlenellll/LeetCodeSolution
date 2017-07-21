public class Solution {
    public void sortColors(int[] nums) {
        int zero = -1, two = nums.length;
        
        for(int i = 0; i < two;){
            if(nums[i] == 1)
                i++;
            else if(nums[i] == 2){
                int temp = nums[--two];
                nums[two] = nums[i];
                nums[i] = temp;
            }else{
                int temp2 = nums[++zero];
                nums[zero] = nums[i];
                nums[i++] = temp2;
            }
        }
        
    }
}