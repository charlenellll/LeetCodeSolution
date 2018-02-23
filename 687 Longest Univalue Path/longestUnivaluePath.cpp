// 65 ms, 69.3%

class Solution {
private:
    int res = 0;
public:
    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;
        dfs(root);
        return res;
    }
    int dfs(TreeNode* root){
        int l = 0, r = 0;
        if( root->left && root->left->val == root->val )
            l = 1 + dfs(root->left);
                            // 这里 l = 0, 递归地在左子树找最大值
        else if( root->left ) dfs(root->left);
        
        if( root->right && root->right->val == root->val )
            r = 1 + dfs(root->right);
                                // 这里 r = 0，递归地在右子树找最大值
        else if( root->right ) dfs(root->right);
        
        // 全局地记录最大值 （鉴于返回值不是这个path长度，返回值是左/右单边的最长路径长度，要不就全局地记录，要不就把最大值这个数的引用传给每个子函数供子函数更改）
        res = max(res, l+r);
        return (l > r) ? l : r;
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