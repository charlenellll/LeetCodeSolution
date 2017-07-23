public class Solution {
    public int minSubArrayLen(int s, int[] nums) {
        int l = 0, r = -1;
        int sum = 0;
        int res = nums.length + 1;
        
        while(l < nums.length){
            if(r+1 < nums.length && sum < s)
                sum += nums[++r];
            else
                sum -= nums[l++];
            if(sum >= s){
                res = Math.min(res, r-l+1); //In Java, have to use Math.min other than min in C++
            }
        }
        if(res == nums.length + 1)
            return 0;
        return res;
    }
}