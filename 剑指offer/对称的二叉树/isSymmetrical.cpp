// 运行时间：3ms 占用内存：476k
class Solution {
private:
    bool isTwoSym(TreeNode* r1, TreeNode* r2){// if two trees are symmetric
        if( !r1 && !r2 ) return true;
        if( !r1 || !r2 ) return false;
        if( r1->val != r2->val ) return false;//保证 r1 && r2 && r1->val == r2->val
        return isTwoSym(r1->left, r2->right) && isTwoSym(r1->right, r2->left);
    }
public:
    bool isSymmetrical(TreeNode* root){
        if( !root ) return true;
        return isTwoSym(root->left, root->right);//左右子树并不需要自己本身是symmetric的
    }

};

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/