// Solution 2: only construct 1 set, remove the element if it is found to avoid duplicates in the result
// 8 ms, faster than 74.79%, mem consumption is smaller

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> record(nums1.begin(), nums1.end()); // notice this shortcut!
        // mem to be optimized: construct the set depending on the smaller vector
        for(auto item: nums2 )
            if( record.find(item) != record.end()){
                res.push_back(item);
                record.erase(item);
            }
        return res;
    }
};


// Solution 1: Brutal force, 2 sets to resolve the duplicate problem
// 8 ms, faster than 74.79%

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> record1, record2;
        for(int i = 0; i < nums1.size(); i++)
            record1.insert(nums1[i]);
        for(int i = 0; i < nums2.size(); i++)
            record2.insert(nums2[i]);
        for(auto item: record1 )
            if( record2.find(item) != record2.end())
                res.push_back(item);
        return res;
    }
};