// 4 ms, faster than 82.42%
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        if( !root ) return sum;
        if( root->left && !root->left->left && !root->left->right )
            sum += root->left->val;
        return sum + sumOfLeftLeaves( root->left ) + sumOfLeftLeaves( root->right );
    }
};