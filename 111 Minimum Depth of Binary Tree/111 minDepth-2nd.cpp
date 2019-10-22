// 8 ms, faster than 96.03%
class Solution {
public:
    int minDepth(TreeNode* root) { //注意:如果一边无child,那么不能用min(left,right)而是用有孩子的那边,即max(left,right)
        if( !root ) return 0;
        int left = minDepth(root->left), right = minDepth(root->right);
        if( left == 0 || right == 0 ) return max(left, right) + 1;
        else return min(left, right) + 1;
    }
};