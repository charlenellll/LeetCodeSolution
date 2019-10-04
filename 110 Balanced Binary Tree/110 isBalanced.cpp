// 8 ms, faster than 97.19% 
class Solution {
private:
    int depth(TreeNode* root){
        if( !root ) return 0;
        int left = depth( root->left );
        int right = depth( root->right);
        if( abs(left - right) > 1 || left == -1 || right == -1 )
            return -1; // not balanced
        return max(left, right) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if( !root ) return true;
        return depth(root) != -1;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */