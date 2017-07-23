public class Solution {
    public int lengthOfLongestSubstring(String s) {
        
        int l = 0, r = -1;
        int res = 0;
        int[] freq = new int[256]; //Java will initiate the array with 0
        
        while( l < s.length()){ // Note that s is a String object
            if( r+1 < s.length() && freq[s.charAt(r+1)] == 0)
                freq[s.charAt(++r)] ++;
            else
                freq[s.charAt(l++)] --;
            res = Math.max(res, r-l+1); // Note that in Java it is Math.max
        }
        return res;
    }
}