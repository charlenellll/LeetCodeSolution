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
        
        if( root == NULL || root->left == NULL ) return root;
        TreeNode* left = root->left, *right = root->right;
        
        // This function will return the new root
        TreeNode* newRoot = upsideDownBinaryTree( root -> left );
        left->right = root;
        left->left = right;
        root->left = NULL, root->right = NULL;
        return newRoot;
    }
};