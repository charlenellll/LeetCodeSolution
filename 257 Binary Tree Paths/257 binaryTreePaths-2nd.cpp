// 0 ms, faster than 100.00%
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if( !root ) return res;
        if( !root->left && !root->right ){
            res.push_back( to_string(root->val) );
            return res;
        }
        vector<string> left = binaryTreePaths(root->left);
        vector<string> right = binaryTreePaths(root->right);
        for(auto item: left)
            res.push_back( to_string(root->val) + "->" + item );
        for(auto item: right)
            res.push_back( to_string(root->val) + "->" + item );
        return res;
    }
};