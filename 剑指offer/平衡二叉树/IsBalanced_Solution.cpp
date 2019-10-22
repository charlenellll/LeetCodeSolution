// 运行时间：3ms 占用内存：484k
class Solution {
private:
    int depth(TreeNode* root){// 返回树的高度（非零），非平衡二叉树则返回-1
        if( !root ) return 0;
        int left = depth(root->left), right = depth(root->right);
        if( left == -1 || right == -1 ) return -1;//1.递归地判断左右子树是否平衡二叉树
        else if( abs(left - right) > 1 ) return -1;//2.检验左右高度之差（确保二者depth都非负再做计算
        else return 1+max(left, right);
    }
public:
    bool IsBalanced_Solution(TreeNode* root) {
        return depth(root) != -1;
    }
};