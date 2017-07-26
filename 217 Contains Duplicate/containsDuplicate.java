public class Solution {
    public boolean containsDuplicate(int[] nums) {
        
        Set<Integer> record = new HashSet();
        
        for(int i = 0; i < nums.length; i++){
            
            if( record.contains(nums[i]) )
                return true;
            record.add(nums[i]);
        }
        return false;
    }
}