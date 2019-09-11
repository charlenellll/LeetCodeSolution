// 8 ms, faster than 74.15%

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> record;
        vector<int> res;
        for( int i = 0; i < nums1.size(); i++)
            record[nums1[i]]++;
        for( int item: nums2 )
            if( record.find(item) != record.end() ){
                res.push_back(item);
                record[item]--;
                if( record[item] == 0 )
                    record.erase(item);
            }
        return res;
    }
};

// simpler code: though no improvement on time
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> record;
        vector<int> res;
        for( int i = 0; i < nums1.size(); i++)
            record[nums1[i]]++;
        for( int item: nums2 )
            if( record[item]-- > 0 ){
                res.push_back(item);
            }
        return res;
    }
};