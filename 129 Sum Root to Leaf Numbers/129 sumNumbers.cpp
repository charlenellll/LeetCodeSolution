// Solution 2: 由于这道题的特殊性，不用vector存path而是直接在递归到底的时候把这根path累加上就好了，O(1) space
// 0 ms, faster than 100.00%
class Solution {
private:
    int sum = 0;
    void sumPath(TreeNode* root, int curPath){
        if( !root ) return;
        curPath = curPath*10 + root->val;
        if( !root->left && !root->right )
            sum += curPath;
        sumPath( root->left, curPath);
        sumPath( root->right, curPath);
    }
public:
    int sumNumbers(TreeNode* root) {
        sumPath( root, 0);
        return sum;
    }
};

// Solution 1: 完全和113思路相同 O(n) time O(logn) space
// 4 ms, faster than 74.31%
class Solution {
private:
    void sumPath(TreeNode* root, int curPath, vector<int>& recordPaths){
        if( !root ) return;
        curPath = curPath*10 + root->val;
        if( !root->left && !root->right )
            recordPaths.push_back( curPath );
        sumPath( root->left, curPath, recordPaths);
        sumPath( root->right, curPath, recordPaths);
    }
public:
    int sumNumbers(TreeNode* root) {
        vector<int> record;
        sumPath( root, 0, record);
        int sum = 0;
        for(auto item: record)
            sum += item;
        return sum;
    }
};