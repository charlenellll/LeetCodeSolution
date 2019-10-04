// Solution 2: 直接利用主函数递归，合理利用返回值（指针）
// 24 ms, faster than 38.56% kinda slow but it is the majority kind of solution
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if( p == q ) return p;
        if( !root || root == p || root == q ) return root;
        // find LCA in left and right child
        TreeNode* l = lowestCommonAncestor(root->left, p, q);// find p or q in left
        TreeNode* r = lowestCommonAncestor(root->right, p, q);// find p or q in right
        if( l && r ) return root; //found p and q in two subtrees
        if( l ) return l;
        if( r ) return r;
        return nullptr;
    }
};

// Solution 1: use a helper function to find a node in a tree (return value is bool)
// 468 ms, faster than 5.08% 
class Solution {
private:
    bool find(TreeNode* root, TreeNode* t){ //find if a node is in a tree
        if( !root ) return false;
        if( root == t ) return true;
        return find(root->left, t) || find(root->right, t);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if( !root ) return nullptr;
        if( root == p || p == q ) return p;
        if( root == q ) return q;
        // find p in left child
        bool pInLeft = find(root->left, p);
        // find q in left child
        bool qInLeft = find(root->left, q);
        if( pInLeft && qInLeft )
            return lowestCommonAncestor(root->left, p, q);
        else if( !pInLeft && !qInLeft )
            return lowestCommonAncestor(root->right, p, q);
        else
            return root;
    }
};