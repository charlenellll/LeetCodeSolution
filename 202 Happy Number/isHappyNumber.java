public class Solution {
    public boolean isHappy(int n) {
        
        if( n == 1 )
            return true;
        
        Set<Integer> sumResult = new HashSet();
        int current = n;
        while( current > 0){
            
            int sum = 0;
            while(current > 0){
                sum += (current % 10) * (current % 10);
                current /= 10;
            }
            if( sum == 1 )
                return true;
            current = sum;
            
            if( sumResult.contains(sum) )
                return false;
            else
                sumResult.add(sum);
        }
        return false;
    }
}