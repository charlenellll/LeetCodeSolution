class Solution {
public:
    bool isHappy(int n) {
        
        if( n == 1 )
                return true;
        
        unordered_set<int> sumResult;
        
        int current = n;
        while( current > 0 ){
            
            int sum = 0;
            while( current > 0){
                sum += (current % 10) * (current % 10);
                current /= 10;
            }
            if(sum == 1)
                    return true;
            current = sum;
            
            if(sumResult.find(sum) != sumResult.end())
                return false;
            else
                sumResult.insert(sum);
        }
        return false;
    }
};