public class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int l = 0, r = numbers.length - 1;
        
        while(l < r){
            if(numbers[l] + numbers[r] == target){
                return new int[] {l+1, r+1}; //Return the results as an array
            }else if(numbers[l] + numbers[r] < target)
                l++;
            else
                r--;
        }
        return new int[] {};
    }
}