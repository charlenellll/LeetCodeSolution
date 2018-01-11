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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        
        TreeNode *node = root, *parent = NULL, *right = NULL;
        while( node != NULL ){
            TreeNode *left = node->left;
            node->left = right;
            right = node->right;
            node->right = parent;
            parent = node;
            node = left;
        }
        return parent;
    }
};