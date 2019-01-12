// 4 ms, 43.63%

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // [0, zero] = 0, (zero, two) = 1, [two, nums.size()-1] = 2
        int zero = -1, two = nums.size();
        int i = 0;
        while( i < two ){
            if( nums[i] == 0 ){
                zero ++;
                if( i != zero ) swap(nums[i], nums[zero]);
                i++;
            }
            else if( nums[i] == 2 ){
                two --;
                if( i != two ) swap( nums[i], nums[two] ); // i will not change in next iteration
            }
            else i++;
        } 
    }
};

// And I find out it really doesn't matter if I test the indexes if they are the same before the swap
// so same speed but more concise (less careful)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // [0, zero] = 0, (zero, two) = 1, [two, nums.size()-1] = 2
        int zero = -1, two = nums.size();
        int i = 0;
        while( i < two ){
            if( nums[i] == 0 ) swap(nums[i++], nums[++zero]);
            else if( nums[i] == 2 ) swap( nums[i], nums[--two] );
            else i++;
        } 
    }
};