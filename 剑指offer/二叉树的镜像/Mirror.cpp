// 运行时间：3ms 占用内存：480k
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if( !pRoot ) return;
        TreeNode* left = pRoot->left, *right = pRoot->right;
        Mirror( left );
        Mirror( right );
        pRoot->left = right;
        pRoot->right = left;
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
};*/