/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


// 12 ms, faster than 57.61%, but seems simpler in lines than the solution below
class Solution {
public:
    int maxDepth(TreeNode* root) {
        
        if( !root ) return 0;
        
        return max( maxDepth(root->left), maxDepth(root->right) ) + 1;
    }
};



// 12 ms, faster than 57.61%

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if( !root ) return 0;
        if( root->left == NULL && root->right == NULL) return 1;
        int leftDepth = 0, rightDepth = 0;
        if( root->left ) leftDepth = maxDepth(root->left) + 1;
        if( root->right ) rightDepth = maxDepth(root->right) + 1;
        return max(leftDepth, rightDepth);
    }
};