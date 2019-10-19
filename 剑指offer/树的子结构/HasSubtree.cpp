// 运行时间：4ms 占用内存：480k
class Solution {
private:
    bool sameTree(TreeNode* r1, TreeNode* r2){ //树1和树2是同一个结构（当r2为空而r1不为空时也算）
        if( !r2 ) return true; //虽然题目规则空树不是任意树的子树，但判断sameTree时是符合的！
        if( r1 && r2 ){
            if( r1->val == r2->val ) return sameTree(r1->left, r2->left) && sameTree(r1->right, r2->right);
            else return false;
        }
        else return false;
    }
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    { // 树1包含树2 or 和树2相同
        if( !pRoot1 || !pRoot2 ) return false;
        return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2) || sameTree(pRoot1, pRoot2);
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