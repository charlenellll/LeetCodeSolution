// 4 ms, beats 100%
// 善用递归函数的返回值，每次递归函数中：
// 1）记录下左子树+右子树的path的最大值
// 2）但只能返回左子树或右子树之间的最大值

class Solution {
private:
    int maxDia = 0;
    int DFS(TreeNode* root){
        int left = 0, right = 0;
        if( root->left ) left = 1 + DFS( root->left );
        if( root->right ) right = 1 + DFS( root->right );
        maxDia = max(maxDia, left + right);
        return max(left, right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if( root == NULL ) return 0;
        DFS(root);
        return maxDia;
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