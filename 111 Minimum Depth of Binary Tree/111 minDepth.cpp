// 16 ms, faster than 40.60% 

class Solution {
public:
    int minDepth(TreeNode* root) {
        if( !root ) return 0;
        int leftDepth = minDepth(root->left), rightDepth = minDepth(root->right);
        if( leftDepth == 0 || rightDepth == 0 ) return max(leftDepth, rightDepth) + 1;
        else return min(leftDepth, rightDepth) + 1;
    }
};


// simpler lines
int minDepth(TreeNode* root) {
    if (!root) return 0;
    int L = minDepth(root->left), R = minDepth(root->right);
    return 1 + (min(L, R) ? min(L, R) : max(L, R));
}