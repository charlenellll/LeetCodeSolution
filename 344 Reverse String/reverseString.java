public class Solution {
    public String reverseString(String s) {
        if(s.length() == 0 || s.length() == 1)
            return s;
        else{
            int l = 0;
            int r = s.length() - 1;
            
            char[] stemp;
            stemp = s.toCharArray();
            while(l < r){
                char temp = stemp[l];
                stemp[l++] = stemp[r];
                stemp[r--] = temp;
            }
            if(l >= r){
                String s2 = new String(stemp);
                return s2;
            }
            else // I don't get it yet, but if this statement is missing, it will be "compile fail"
                return s;
        }
    }
}