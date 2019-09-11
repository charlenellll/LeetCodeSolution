//0 ms, faster than 100.00%
class Solution {
private:
    bool isSym(TreeNode* p, TreeNode* q){
        if( !p && !q ) 
            return true;
        else if( p && q && p->val == q->val )
            return isSym(p->left, q->right) && isSym(p->right, q->left);
        else
            return false;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if( !root ) 
            return true;
        return isSym(root->left, root->right);
    }
};