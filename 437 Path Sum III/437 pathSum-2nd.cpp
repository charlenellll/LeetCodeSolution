// 20 ms, faster than 76.49%
class Solution {
private:
    int pathSumCons(TreeNode* root, int sum){ // 必须连续
        if( !root ) return 0;
        int res = 0;
        if( root->val == sum ) res++;
        return res + pathSumCons(root->left, sum - root->val) + pathSumCons(root->right, sum - root->val);
    }
public:
    int pathSum(TreeNode* root, int sum) { // 包含不连续
        if( !root ) return 0;
        return pathSumCons( root, sum ) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};