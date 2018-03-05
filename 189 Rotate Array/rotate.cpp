// O(n) time O(1) space
// 4. reverse the last part + reverse the rest + reverse the whole vector together

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int curNum;
        int n = nums.size();
        int pos = n - k % n;
        reverse(nums.begin()+pos, nums.end());
        reverse(nums.begin(), nums.begin()+pos);
        reverse(nums.begin(),nums.end());
    }
};


// O(n) time O(n) space
// 1. Straight forward: record the rotated array and replace the original array with it
// 22 ms

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();
        int start = n - k % n;
        for(int i = start; i < n; i++ ) res.push_back(nums[i]);
        for(int i = 0; i < start; i++ ) res.push_back(nums[i]);
        nums = res;
    }
};

// O(n^2) time because i used insert(), O(1) space
// 3. inspired by solution 2, but it is O(1) space
// 68 ms, beats 5.38% (slowwwww)

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int curNum;
        int n = nums.size();
        for(int i = 1; i <= k % n; i++ ) {
            curNum = nums[n-1];
            nums.pop_back();
            nums.insert(nums.begin(), curNum);
        }
    }
};

// O(n^2) time because I used insert(), O(k) space
// 2. space is smaller than solution 1 but time is too much
// 79 ms

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> record;
        int n = nums.size();
        for(int i = n - k % n; i < n; i++ ) {
            record.push_back(nums[i]);
            nums.pop_back();
        }
        for(int i = record.size()-1; i >= 0; i-- ) nums.insert(nums.begin(), record[i]);
    }
};