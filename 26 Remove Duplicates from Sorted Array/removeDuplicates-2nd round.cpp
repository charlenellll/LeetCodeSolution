// 35 ms, beats 35%
// 完全没有考虑到题目情况！！！！Sorted Array!!! 根本不需要另开一个set！！！

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