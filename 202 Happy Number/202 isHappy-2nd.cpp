// 4 ms, faster than 66.56% 

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> record;
        int num = n;
        while( num != 1 ){
            int sum = 0;
            for(int i = num; i > 0; i /= 10 )
                sum += pow(i % 10, 2);
            if( sum == 1 ) return true;
            if( record.find(sum) != record.end())
                return false;
            record.insert(sum);
            num = sum;
        }
        return true;
    }
};