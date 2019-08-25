// 35 ms, beats 35%
// 完全没有考虑到题目情况！！！！Sorted Array!!! 根本不需要另开一个set！！！
// BAD!

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> record;
        int k = 0; // 要保留元素所应放到的位置， [0,k)为已放的保留元素
        for(int i = 0; i < nums.size(); i++){
            if( record.find( nums[i]) == record.end() ){
                record.insert( nums[i] );
                if( i != k ){
                    swap( nums[i], nums[k]);
                    k++;
                }
                else
                    k++;
            }
        }
        return k;
    }
};

// 考虑到sorted array 后：
// 28 ms, beats 53.78%

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if( nums.size() == 0 ) return 0;
        int k = 1;
        for( int i = 1; i < nums.size(); i++){
            if( nums[i] > nums[k-1] ){
                if( i != k ) swap(nums[i], nums[k++]);
                else k++;
            }
        }
        return k;
    }
};

// 或者不调用swap，直接赋值也行， 速度相同

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if( nums.size() == 0 ) return 0;
        int k = 1;
        for( int i = 1; i < nums.size(); i++){
            if( nums[i] > nums[k-1] ){
                if( i != k )  nums[k++] = nums[i];
                else k++;
            }
        }
        return k;
    }
};


// 20 ms, faster than 93.00% 

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if( nums.size() == 0 ) return 0;
        int k = 1; // [0,k) are non-duplicate elements
        for(int i = 1; i < nums.size(); i++){
            if( nums[i] > nums[k-1] ){
                if( i != k ) swap(nums[i], nums[k]);
                k++;
            }
        }
        return k;
    }
};