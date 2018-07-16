// 40ms
// 99.91%
// NOT easy for an easy question.

class Solution {
private:
    int res = 0;
    // longest univalue path not necessary contain this node
    int dfs(TreeNode* root){
        if( root == NULL ) return 0;
        int l = 0, r = 0;
        if(root->left && root->left->val == root->val)
            l = 1 + dfs(root->left);
        else
            dfs(root->left);
        
        if(root->right && root->right->val == root->val )
            r = 1 + dfs(root->right);
        else
            dfs(root->right);

        // NOTE THAT!! the longest path may be two subtree path connected through the root! YEES it is a path!!
        res = max(res, l+r);
        
        // NOTE THAT!! when you return, you can only return the longest left/right subtree path, because for current root's father, the path cannot be connected
        return max(l,r);
    }
public:
    // longest univalue path having this node
    int longestUnivaluePath(TreeNode* root) {
        if(root == NULL) return 0;
        dfs(root);
        return res;
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