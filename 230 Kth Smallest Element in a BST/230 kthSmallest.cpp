// 20 ms, faster than 81.28%
class Solution {
private:
    int count(TreeNode* root){ //返回树有多少个节点
        if( !root ) return 0;
        return 1 + count(root->left) + count(root->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int a = count(root->left);
        if( k == a + 1 ) return root->val;
        else if( k > a + 1 )
            return kthSmallest(root->right, k-a-1);
        else
            return kthSmallest(root->left, k);
    }
};