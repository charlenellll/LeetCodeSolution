/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        
        if( root == NULL )
            return false;
        // The path needs to be root-to-leaf, so if root->val == sum, it can't have any children
        if( root->val == sum && root->left == NULL && root->right == NULL )
            return true;
        // Or the 2 lines above can be
        // if( root->left == NULL && root->right == NULL )
        // 	return root->val == sum;
        bool res = hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
        return res;
    }
};