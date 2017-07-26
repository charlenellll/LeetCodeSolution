public class Solution {
    public int[] twoSum(int[] nums, int target) {
        
        Map<Integer, Integer> record = new HashMap<Integer, Integer>();
        for(int i = 0; i < nums.length; i++){
            
            int complement = target - nums[i];
            if( record.containsKey(complement) ){
                int[] res = {i, record.get(complement)};
                return res;
            }
            
            record.put(nums[i], i);
        }

        // Java is really strict on rules. If I don't add these two lines, the compilation cannot pass
        int[] null_res = null;
        return null_res;
    }
}