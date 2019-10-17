// 3ms
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {// 返回头结点,用left指向前面的元素,用right指向后面的元素
        // Base case
        if( !pRootOfTree || (pRootOfTree && !pRootOfTree->left && !pRootOfTree->right) ) return pRootOfTree; // 只有一个结点
        TreeNode* leftHead = Convert(pRootOfTree->left);
        TreeNode* rightHead = Convert(pRootOfTree->right);
        TreeNode* leftTail = leftHead; // 注意leftHead可能为空所以后续需要判断
        while( leftTail && leftTail->right )
            leftTail = leftTail->right;
        if(leftTail){
            leftTail->right = pRootOfTree;
            pRootOfTree->left = leftTail;
        }
        if( rightHead ){
            rightHead->left = pRootOfTree;
            pRootOfTree->right = rightHead;
        }
        return (leftHead) ? leftHead : pRootOfTree;
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