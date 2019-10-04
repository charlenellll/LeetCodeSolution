// 12 ms, faster than 88.36%
class Solution {
private:
    bool edgeValue(TreeNode* root, int v, bool isLeft){
        if( !root ) return true;
        TreeNode* cur = root;
        if( isLeft ){
            if( !cur->right ) return true;
            while( cur->right )
                cur = cur->right;
            if( cur->val < v ) return true;//左子树最大值
            else return false;
        }
        else{
            if( !cur->left ) return true;
            while( cur->left )
                cur = cur->left;
            if( cur->val > v ) return true;//右子树最小值
            else return false;
        }
    }
public:
    bool isValidBST(TreeNode* root) { //左子树所有值小于root，右子树所有值大于root
        if( !root ) return true;
        if( !root->left && !root->right ) return true;
        if( root->left && root->left->val >= root->val ) return false; //必须严格小于
        if( root->right && root->right->val <= root->val ) return false; //必须严格大于
        return isValidBST(root->left) && isValidBST(root->right) && edgeValue(root->left, root->val, true) && edgeValue(root->right, root->val, false);
    }
};